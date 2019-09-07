#include <czlibrary/czlibrary.h>

#include <QString>


void CzLibrary::Log(string info){
    if(IS_DEBUG){
        cout << info << endl;
    }
}

void CzLibrary::LibraryLog(string info){
    if(IS_LIBRARY_DEBUG){
        cout << info <<endl;
    }
}

