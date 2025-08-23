
- `setw(n)`: print always atleast range n
- `setfill('x')`: fill `setw` if number shorter `n`
- `setprecision(n)`: print float always exactly n number after comma

    ```cpp
    cout<<setw(n)<<setfill(' ')<<setprecision(2);
    ```