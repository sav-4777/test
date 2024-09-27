
/* main.cpp */
#include <iostream>
#include <fstream>
#include <regex>
#include <map>

using namespace std;

int main()
{
    string str;
    ifstream infile("/proc/meminfo");
    ofstream outfile_unsorted("meminfo_unsotred");
    ofstream outfile_sort("meminfo_sort");
    ofstream outfile_sort_all("meminfo_sort_all");
   
    string str_1;
    int size_mem;
    
    map <int, string> mp;
    multimap <int, string> mmp;
    
    
    
    //stage 1: it's reading and processing file
	if ( infile.is_open() && outfile_unsorted.is_open() ) {
		while ( getline(infile,str) ) {
            
            istringstream iss(str);
			iss >> str_1;
			iss >> size_mem;
            
            str.erase( remove(str.begin(), str.end(), ':' ), str.end() );
            
            if ( size_mem == 0 ) {
                replace( str.begin(), str.end(), '0', '-' );
                str.erase( str.find('-') + 1 );
            } 
            else {
                mp.insert( pair<int, string>(size_mem, str) );
            }
            
            mmp.insert( pair<int, string>(size_mem, str) );
            
            outfile_unsorted << str << endl;
		}
		
		infile.close();
        outfile_unsorted.close();
	}
	else {
		cout << "ERROR: Unable to open files: meminfo or meminfo_unsotred" << endl; 
		return -1;
	}
    
    
    
    //stage 2: it's writing data to a file
    if ( outfile_sort.is_open() && outfile_sort_all.is_open() ) {
        for (auto it : mp) {
            outfile_sort << it.second << endl;
        }
        for (auto it : mmp) {
            outfile_sort_all << it.second << endl;
        }
        
        outfile_sort.close();
        outfile_sort_all.close();
    }
    else {
		cout << "ERROR: Unable to open files: meminfo_sort or meminfo_sort_all" << endl; 
		return -1;
	}
    
    
    
    cout << "INFO: Ok." << endl;

    return 0;
}
