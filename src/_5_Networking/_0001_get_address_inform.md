# Referrences:
- [man page](https://man7.org/linux/man-pages/man3/getaddrinfo.3.html)

# Content
- `getaddrinfo()`
    - [syntax](#syntax)
    - [parameter](#parameters)
- `struct addrinfo`
    - [template](#template)
    - [member](#struct-member)
- `struct sockaddr`
    - [Beej’s Guide](https://beej.us/guide/bgnet/html/split/ip-addresses-structs-and-data-munging.html#structs)

## getaddrinfo
### Syntax: 
```cpp
int getaddrinfo(const char *restrict node,
                       const char *restrict service,
                       const struct addrinfo *restrict hints,
                       struct addrinfo **restrict res);
```
### Parameters:
- `const char* node`
    - Specifies the hostname or IP address to resolve when `hints` is configured for a **client**.
        - The function will return results based on the `ai_flags` settings.
    - Pass `NULL` when `hints` is configured for a **server** with `AI_PASSIVE` set in `ai_flags`.
        - This allows the function to return wildcard addresses (0.0.0.0 for IPv4 or :: for IPv6), which are suitable for binding.

- `const char* service`
    - The port number or service name (e.g., "http" or "443").
    - If `NULL`, the caller must set the port manually in the returned address structures.

- `struct addrinfo* hints`
    - A pointer to a struct addrinfo that specifies hints for filtering results.
    - If `NULL`, the function returns results with default settings (allowing both IPv4 and IPv6).

- `struct addrinfo** res`
    - A pointer to a struct addrinfo* that will be filled with a linked list of results.
    - The caller is responsible for freeing the list using `freeaddrinfo()`.

## struct addrinfo
### template:
    ```cpp
    struct addrinfo
    {
        int ai_flags;
        int ai_family;
        int ai_socktype;
        int ai_protocol;
        socklen_t ai_addrlen;
        struct sockaddr *ai_addr;
        char *ai_canonname;
        struct addrinfo *ai_next;
    };
    ```

### struct member
- `ai_flags`:
    - Specifies options for address lookup.
    - check more define macro in <netdb.h>
    ```cpp
    #define AI_PASSIVE     0x0001  /* Suitable for `bind()` */
    #define AI_CANONNAME   0x0002  /* Request canonical name */
    #define AI_NUMERICHOST 0x0004  /* Don't resolve hostname */
    #define AI_V4MAPPED    0x0008  /* Return IPv4-mapped IPv6 address */
    #define AI_ALL         0x0010  /* Return all matching addresses */
    #define AI_ADDRCONFIG  0x0020  /* Only return addresses configured on the system */
    ```
- `ai_family`: 
    - Specifies the `address` family.
    - Common values: more macro in <socket.h>
        - `AF_INET` for IPv4
        - `AF_INET6` for IPv6
        - `AF_UNSPEC` for any supported address family

- `ai_socktype`: 
    - Specifies the socket type.
    - Common values: more macro in <socket_type.h>
        - `SOCK_STREAM` for TCP
        - `SOCK_DGRAM` for UDP

- `ai_protocol`: 
    - Specifies the protocol used.
    - Common values:
        - `IPPROTO_TCP`
        - `IPPROTO_UDP`
        - `0` for automatic selection

- `ai_addrlen`: 
    - The `length` (in `bytes`) of the socket `address` pointed to by `ai_addr`.

- `ai_addr`: 
    - Pointer to a `sockaddr structure` that will holds the `resolved address` after using `getaddrinfor()`

- `ai_canonname`: 
    - If `AI_CANONNAME` is set in ai_flags, this will contain the canonical hostname.

- `ai_next`: 
    - Pointer to the next addrinfo structure in the linked list.
