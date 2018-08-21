#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "fcgio.h"
#include "RequestManager.h"

using namespace std;

const unsigned long STDIN_MAX = 1000000;



int main(void) {
    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        const char * uri = FCGX_GetParam("REQUEST_URI", request.envp);
        //string s = uri;
        //string content = get_request_content(request);
        cout << "Content-type: application/json\r\n\r\n";

        //cout << "Content-type: text/html\r\n\r\n";
        RequestManager::parse(uri);
        //makejson(cout,content);
        //makejson(cout,s); -->last used
        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
