#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Subscriber {
public:
	long sTime;
	double sLat;
	double sLong;
	long sPhone;

	Subscriber(vector<string> fields, int timeCol, int latCol, int longCol, int phoneCol) {
		struct tm when;
		strptime(fields[timeCol].c_str(), "%m/%d/%Y %H:%M", &when);
		sTime = mktime(&when);
		sLat = stod(fields[latCol]);
		sLong = stod(fields[longCol]);
		sPhone = stol(fields[phoneCol]);
	}

	void print() {
		cout << fixed << sTime << "|" << sLat << "|" << sLong << "|" << sPhone << endl;
	}
};

double haversine(double lat1, double long1, double lat2, double long2) {
	lat1 *= 3.14159265/180;
	long1 *= 3.14159265/180;
	lat2 *= 3.14159265/180;
	long2 *= 3.14159265/180;
	return 2 * 6378.137 *
		asin(
			sqrt(
				pow(
					sin(
						(lat1 - lat2) / 2
					)
					+ cos(lat1)
					* cos(lat2)
					* pow(
						sin(
							(long1 - long2) / 2
						)
						, 2
					)
					, 2
				)
			)
		);
}

vector<string> split(const char *str) {
    vector<string> result;
    do {
        const char *begin = str;

        while(*str != ',' && *str) {
            str++;
        }

        result.push_back(string(begin, str));
    } while(0 != *str++);

    return result;
}

int main() {
	double mLat = 0.0;
	double mLong = 0.0;
	double r = 0.0;

	string mLatLong;
	cin >> mLatLong;
	mLat = stod(mLatLong.substr(0, mLatLong.find(',')).c_str());
	mLong = stod(mLatLong.substr(mLatLong.find(',')+1).c_str());

	cin >> r;

	vector<Subscriber> v;
	string line;
	getline(cin, line);	//Drop empty row

	getline(cin, line);	//Get header row
	int timeCol = 0;
	int latCol = 1;
	int longCol = 2;
	int phoneCol = 3;
	vector<string> header = split(line.c_str());
	for(int i = 0; i < header.size(); i++) {if(header[i].compare("Date&Time") == 0) timeCol = i;}
	for(int i = 0; i < header.size(); i++) {if(header[i].compare("Latitude") == 0) latCol = i;}
	for(int i = 0; i < header.size(); i++) {if(header[i].compare("Longitude") == 0) longCol = i;}
	for(int i = 0; i < header.size(); i++) {if(header[i].compare("PhoneNumber") == 0) phoneCol = i;}

	while(getline(cin, line)) {
		vector<string> fields = split(line.c_str());
		Subscriber sub(fields, timeCol, latCol, longCol, phoneCol);
		for(auto it = v.begin(); it != v.end(); it++) {
			if(it->sPhone == sub.sPhone && it->sTime < sub.sTime) {
				v.erase(it);
			}
		}
		v.push_back(sub);
	}

	if(v.size() > 0) {
		vector<long> phoneNums;
		for(Subscriber s : v) {
			double d = haversine(mLat, mLong, s.sLat, s.sLong);
			if(d < r) {
				phoneNums.push_back(s.sPhone);
			}
		}

		if(phoneNums.size() > 0) {
			sort(phoneNums.begin(), phoneNums.end());
			for(int i = 0; i < phoneNums.size() - 1; i++) {
				cout << phoneNums.at(i) << ",";
			}
			cout << phoneNums.back();
		}
	}
	cout << endl;

	return 0;
}
