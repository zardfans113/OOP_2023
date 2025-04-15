#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
using namespace std;

struct info {
	int id;
	int score;

	// don't change this
	bool operator<(const info& other) const {
		return id < other.id;
	}
};
bool score_swap(const pair<string, info>& a, const pair<string, info>& b) {
	return a.second.score < b.second.score;
};
bool id_swap(const pair<string, info>& a, const pair<string, info>& b) {
	return a.second.id < b.second.id;
};
bool score_id_swap(const pair<string, info>& a, const pair<string, info>& b) {
	if (a.second.score == b.second.score) return a.second.id < b.second.id;
	else return a.second.score < b.second.score;
};
//TODO: implement three comparsion function 
//example: 
//bool functionName(const dataType& p1, const dataType& p2) {
//	return p1 > p2;
//}

//1.implement compare by score here

//2.implement compare by id here

//3.implement compare by score and id here


class Map
{
private:
	vector<pair<string, info>> student;
public:
	Map()
	{
		student.clear();
	}

	void readFile() {
		fstream file;
		file.open("HIDDEN.txt", ios::in);
		if (file.fail())
		{
			printf("open file failed\n");
			exit(1);
		}
		int cmdNum;
		file >> cmdNum;

		while (cmdNum--) {
			char cmd;
			file >> cmd;
			switch (cmd) {
				case 'a':
				{
					string name;
					file >> name;
					info ii;
					file >> ii.id >> ii.score;
					add(name, ii);
					break;
				}
				case 'f':
				{
					string name;
					file >> name;
					find(name);
					break;
				}
				case 'e':
				{
					string name;
					file >> name;
					erase(name);
					break;
				}
			}
		}

		file.close();
	}

	void add(string name, info& _info) {
		bool exist = false;
		for (int i = 0; i < student.size(); i++) {
			if (student[i].first == name) {
				cout << name << "'s ID:" << student[i].second.id << " and Score:" << student[i].second.score;
				cout << " is changed to ID:";
				student[i].second.score = _info.score;
				student[i].second.id = _info.id;
				cout << student[i].second.id << " and Score:" << student[i].second.score << endl;
				exist = true;
				break;
			}
		}
		if (!exist) {
			student.push_back(pair<string, info>(name, _info));
		}
		//if the student is already in the vector,override it
		//else add the student to the vector
		//TODO: implement add function add new data into the map(vector<pair<...>>)
		//If the name is already in the map, override his/her data
		
	}
	void find(string name) {
		bool found = false;
		for (vector<pair<string, info>>::iterator it = student.begin(); it != student.end(); ++it) {
			if (it->first == name) {
				cout << it->first << " is found!  ID:" << it->second.id << " and Score:" << it->second.score << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << name << " is not found!" << endl;
		}
		//An iterator is an object that points to an element within a container (such as a vector, map, or set) 
		// and allows us to traverse the elements of the container. 
		// It acts like a pointer that can be incremented or decremented to point to the next or previous element in the container. 
		// With iterators, we can perform various operations on the elements of a container, 
		// such as accessing, modifying, inserting, and deleting elements. Iterators are used extensively in C++ STL algorithms and containers.
		//TODO: implement find function to get the information of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
	}
	void erase(string name) {
		vector<pair<string, info>>::iterator it;
		bool found = false;
		for (it = student.begin(); it != student.end(); ++it) {
			if (it->first == name) {
				found = true;
				cout << it->first << " is erased!" << endl;
				break;
			}
		}
		if (found) {

			student.erase(it);
		}
		else {
			cout << name << " is not found" << endl;
		}
		//TODO: implement erase function to delete the element of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
	}

	void sortByName() {
		sort(student.begin(), student.end());
		//TODO: call sort() function (default one)
	}

	void sortByInfo(const char* type) {

		if (type == string("SC")) {
			sort(student.begin(), student.end(), score_swap);
			//TODO: call sort() function and compare by score
		}
		else if (type == string("ID")) {
			sort(student.begin(), student.end(),id_swap);
			//TODO: call sort() function and compare by id
		}
		else if (type == string("SCID")) {
			sort(student.begin(), student.end(), score_id_swap);
			//TODO: call sort() function and compare by score and id
		}
	}

	void write(fstream& file) {
		vector<pair<string, info>>::iterator it;
		for (it = student.begin(); it != student.end(); ++it) {
			int tmp = it->first.size();
			int tmp1 = 10 - tmp;
			if (it->second.id < 10)
			{
				tmp1--;
				file << it->first << ":" << setw(tmp1) << it->second.id << ", " << it->second.score << endl;
			}
			else file << it->first  << ":"<< setw(tmp1) << it->second.id  <<", " << it->second.score << endl;
			if (it == student.end() - 1) file << endl;
		}
		//TODO: Write all elements in the map to the file
		//you must use iterator to implement
	}

	void writeFile() {
		fstream file;
		file.open("lab7.txt", ios::out);
		if (file.fail())
		{
			printf("open file failed\n");
			exit(1);
		}

		file << "Sort By Name\n";
		sortByName();
		write(file);
		file << "Sort By Score\n";
		sortByInfo("SC");
		write(file);
		file << "Sort By ID\n";
		sortByInfo("ID");
		write(file);
		file << "Sort By Score&ID\n";
		sortByInfo("SCID");
		write(file);

		cout << "File lab7.txt saved!\n";
		file.close();
	}
};

int main() {
	Map myMap;

	myMap.readFile();
	myMap.writeFile();

	system("pause");
	return 0;
}
