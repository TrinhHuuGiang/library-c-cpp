# Using `dirent.h` in C

## Main Functions in `dirent.h`:

1. **`opendir()`**: Opens a directory.
   - `DIR *opendir(const char *dirname);`
   - Returns a `DIR` pointer on success, or `NULL` on failure.

2. **`readdir()`**: Reads one entry in the directory.
   - `struct dirent *readdir(DIR *dirp);`
   - Returns a pointer to `dirent` containing information about the next entry.  
   Returns `NULL` when no more entries are available.

3. **`closedir()`**: Closes a directory.
   - `int closedir(DIR *dirp);`
   - Returns `0` on success, or `-1` on failure.

4. **`rewinddir()`**: Resets the directory reading position to the beginning.
   - `void rewinddir(DIR *dirp);`

5. **`telldir()`**: Retrieves the current position in the directory.
   - `long telldir(DIR *dirp);`

6. **`seekdir()`**: Moves the directory pointer to a specified position.
   - `void seekdir(DIR *dirp, long loc);`

## `dirent` Structure

```cpp
struct dirent {
    ino_t d_ino;              // Inode number
    off_t d_off;              // Offset within the directory
    unsigned short d_reclen;  // Length of the entry
    unsigned char d_type;     // Type of the entry (file, directory, etc.)
    char d_name[256];         // Name of the entry
};
