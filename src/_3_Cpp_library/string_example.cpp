// Parse HRML example
// 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define NOT_FOUND_STR "Not Found!"


bool Is_root_tag(const vector<string>& data, const string& tag, int* root_line);


// find tag inside
// return true if inside
// else return false
// id_line keep line exist child tag
bool Is_tag_inside(const vector<string>& data, const string& parent_tag,const string& child_tag, const int& parent_line, int* child_line);

// find value by key
// input line
// return value found or `Not Found!`
string value_of_key(const vector<string>& data, const string& key, const int line);


int main() {
    vector<string> data;
    vector<string> quer;
    
    int num_line_data, num_quer;
    
    cin>>num_line_data>>num_quer;
    
    string xxx;
    getline(cin, xxx);
    
    // get data
    for(int i = 0 ; i < num_line_data ; i++)
    {
        string tmp_input;
        
        getline(cin, tmp_input);
        
        data.push_back(tmp_input);
        
        // cout << "====data" << i << data[i]<<endl;
    }
    
    // get query
    for(int i = 0 ; i < num_quer ; i++)
    {
        string tmp_input;
        
        getline(cin, tmp_input);
    
        quer.push_back(tmp_input);
        
        
        // cout << "\\\\quer" << i << quer[i]<<endl;
    }
    
    // handle
    for(int i = 0; i < num_quer; i++)
    {
        // cout<< "Quer "<<i<<" |"<<quer[i]<<endl;

        int mid_pos = quer[i].find('~');
        
        // no ~
        if(mid_pos == string::npos)
        {
            cout<<NOT_FOUND_STR<<endl;
            continue;
        }
        
        // else
        else 
        {
            // get key after ~
            string key = quer[i].substr(mid_pos+1, string::npos);
            
            // get link before ~
            stringstream link(quer[i].substr(0, mid_pos));
            
            // parse to vector parent child
            vector<string> par_chi;
            
            while(!link.eof())
            {    
                string tmp_str;
                getline(link, tmp_str, '.');
                
                par_chi.push_back(tmp_str);
            }
            
            // check parent child
            int parent_line = 0, child_line = 0;
            bool exist_child = true;
            int par_chi_size=par_chi.size();


            // check root
            if(! Is_root_tag(data, par_chi[0], &parent_line))
            {
              // cout<< "Missing root"<<endl;

              cout<<NOT_FOUND_STR<<endl;
              continue;
            }
            else // ok match root
            {
              if(par_chi_size == 1)
              {
                exist_child = true;
              }
              else
              {
                for(int pc = 0; pc < par_chi_size-1; pc ++)
                {

                    if(Is_tag_inside(data, par_chi[pc], par_chi[pc+1], parent_line, &child_line))
                    {
                        parent_line = child_line;
                        // cout<<"PL update"<<parent_line<<endl;
                    }
                    else
                    {
                        cout<<NOT_FOUND_STR<<endl;
                        exist_child = false;
                        break;
                    }
                }
              }

              // child exist
              if(exist_child)
              {
                  cout<< value_of_key(data, key, parent_line)<<endl;
              }
            }

        }
    }
    
    return 0;
}


bool Is_root_tag(const vector<string>& data, const string& tag, int* root_line)
{
  // cout << "Root testing: " << tag<<endl;

  int num_line = data.size();

  bool is_root = false;

  bool find_a_root = false;

  string tmp_root_key;

  // then compare with tag
  for(int i = 0; i<num_line ; i++)
  {
    string tmp_tag;
    stringstream sp(data[i]);
    sp>>tmp_tag; 
    
    // start find a root
    if(!find_a_root)
    {
      find_a_root = true;

      // cout << "Found a root: " << tmp_tag <<endl;

      // if right root -> return true
      // else try end current root , find next root
      if(tmp_tag == string("<") + tag ||
        tmp_tag == string("<") + tag + string(">"))
      { 
        is_root = true;
        *root_line = i;
        break;
      }

      else
      {
        if(tmp_tag.find(">") != string::npos)
          {
            stringstream tmpss(tmp_tag.substr(1, tmp_tag.size() - 2));
            tmpss >> tmp_root_key;
          }
        else
          {
            stringstream tmpss(tmp_tag.substr(1, string::npos));
            tmpss >> tmp_root_key;
          }
      }
    }
    // check end of root 
    else
    {
      stringstream sp(data[i]);

      string tmp_end_tag;

      sp>> tmp_end_tag;
      
      int wh = tmp_end_tag.find("</");

      // check right end root
      if(wh != string::npos)
      {
        // match root end - start
        if(tmp_tag == string("</") + tmp_root_key ||
          tmp_tag == string("</") + tmp_root_key + string(">"))
        {
          find_a_root = false;
        }
      }
      else continue;
    }

  }

  return is_root;
}


bool Is_tag_inside(const vector<string>& data, const string& parent_tag,const string& child_tag,const int& parent_line, int* child_line)
{
    int num_line = data.size();
    
    if(parent_line<0) return false;
    
    // find parent tag, check child_tag exist
    for(int i = parent_line; i<num_line ; i++)
    {
        stringstream sp(data[i]);
        string tmp_ptag;
        sp>>tmp_ptag;
        
        if(tmp_ptag == string("<") + parent_tag ||
           tmp_ptag == string("<") + parent_tag + string(">"))
        {
            // cout<< "Found parent: "<<parent_tag<<endl;

            int in_scope = false;
            string child_scope;
            
            for(int j = i+1;j<num_line;j++)
            {
                stringstream sc(data[j]);
                string tmp_ctag;
                sc>>tmp_ctag;

                // check out of parent range
                // check right child
                // continue
                if (tmp_ctag == string("</") + parent_tag ||
                    tmp_ctag == string("</") + parent_tag + string(">"))
                {
                    // cout<< "End parent tag: "<<tmp_ctag<<endl;
                    return false;
                }
                else if(tmp_ctag == string("<") + child_tag ||
                    tmp_ctag == string("<") + child_tag + string(">"))
                {
                    if(in_scope)
                    {
                      return false;
                    }
                    
                    // cout<< "Found child: "<<child_tag<<endl;
                    *child_line = j;
                    return true;
                }
                else 
                {
                  // cout << "here"<<endl;
                  if(in_scope)
                  {
                    // cout << "here"<<endl;
                    if(tmp_ctag == string("</") + child_scope ||
                      tmp_ctag == string("</") + child_scope + string(">"))
                      {
                        in_scope = false;
                      }
                  }

                  else
                  {
                    // cout << "here"<<endl;

                    // if is new tag, on scope
                    if(tmp_ctag.find("</") == string::npos)
                    {
                      if(tmp_ctag.find('>')!= string::npos)
                      {
                        stringstream scp(tmp_ctag.substr(1,tmp_ctag.size() -2));
                        scp>>child_scope;
                      }
                      else
                      {
                        stringstream scp(tmp_ctag.substr(1,string::npos));
                        scp>>child_scope;
                      }

                      // cout<<"Dive in scope: " <<child_scope<<endl;
                      in_scope = true;
                    }
                  }  
                }
            }
        }
    }
    
    // end
    return false;
}

string value_of_key(const vector<string>& data, const string& key, const int line)
{
    string data_line = data[line];

    int wh = string::npos + 1;

    int curpos = 0;

    while(wh != string::npos)
    {
      wh = data_line.find(string(" ") + key, curpos);
      
      if(wh == string::npos)
      {
          return string(NOT_FOUND_STR);
      }

      curpos = wh;

      int wheq = data_line.find("=", wh);

      string raw_key = data_line.substr(wh+1, wheq-1-wh);

      if(!raw_key.compare(key))
      {
        continue; 
      }

      else
      {
        stringstream ss_value(data_line.substr(wheq+1, string::npos));

        string value;

        ss_value >> value;

        if(value.find(">") != string::npos)
        {
          return value.substr(1,value.size()-3);
        }
        
        return value.substr(1,value.size()-2);
      }

    }

    return string(NOT_FOUND_STR);
}