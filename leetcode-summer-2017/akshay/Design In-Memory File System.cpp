#include<map>
#include<set>
#include<vector>
#include <iostream>
#include<vector>
#include<sstream>
using namespace std;

class FileSystem {
public:
    map<string,set<string> > directoryMap;
    map<string,string> fileMap;

    FileSystem() {
        directoryMap["/"];
    }

    vector<string> ls(string path) {
      if(directoryMap.find(path)!=directoryMap.end())
      {
        vector<string> listDirectory(directoryMap[path].begin(),directoryMap[path].end());
        return listDirectory;
      }
      else
      {
        vector<string> splittedPath = splitPath(path);
        vector<string> listDirectory(splittedPath.end()-1,splittedPath.end());
        return listDirectory;
      }
    }

    vector<string> splitPath(string path)
    {
        path = path.substr(1);
        stringstream pathStream(path);
        vector<string> splittedPath;
        char delimiter = '/';
        while(pathStream.good())
        {
          string buffer;
          getline(pathStream,buffer,delimiter);
          splittedPath.push_back(buffer);
        }
        return splittedPath;
    }


    void mkdir(string path){
      string currentDirectory = "/";
      vector<string> directories = splitPath(path);
      for(int i=0; i<directories.size();i++)
      {
        //check directories[i] is in current directory else add
        directoryMap[currentDirectory].insert(directories[i]);

        //create new directory
        if(i==0)
        {
            directoryMap[currentDirectory+directories[i]];
            currentDirectory = currentDirectory + directories[i];
        }
        else
        {
          directoryMap[currentDirectory+"/"+directories[i]];
          currentDirectory = currentDirectory + "/" + directories[i];
        }
      }
    }

    void printDirectoryMap()
    {
      for(map<string,set<string> >::iterator it = directoryMap.begin(); it!=directoryMap.end();it++)
      {
        cout<<"Directory ";
        cout<<it->first<<endl;
        for(set<string>::iterator j=it->second.begin();j!=it->second.end();j++)
        {
          cout<<*j<<endl;
        }
        cout<<"Done"<<endl;
      }
    }

    void addContentToFile(string filePath, string content) {
      vector<string> splittedPath = splitPath(filePath);
      string directoryPath;
      for(int i=0;i<splittedPath.size()-1;i++)
      {
        directoryPath += "/" + splittedPath[i];
      }
      directoryMap[directoryPath].insert(splittedPath.back()) ;
      fileMap[filePath] = fileMap[filePath] + content;
    }

    string readContentFromFile(string filePath) {
      return fileMap[filePath];
    }
};

/** unit testing of functions worked.
 time taken was too much
 missing somethings
 **/

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
