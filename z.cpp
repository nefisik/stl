3PQKGwS15FuuyHwDFhE1Zb7BPKA9uWLyivg
//seed:
daring club clap blast error name kick enemy naive jump husband artist reopen skate embark

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string result(string& Str1, string& str2) {
	if(Str1.size()<str2.size()) { swap(Str1,str2); }
	string str1 = Str1;
	string arr="";
	int size1 = str1.size();
	int size2 = str2.size();
	int flag = str1.size();
	int i = 0, j = 0;
	switch (flag) {
		case 0:
			return "0";
			break;
		case 1:
			return to_string(stoi(str1)+stoi(str2));
		default:
			for(i=size1-1; i>=size1-size2-1; --i) {
				for(j=size2-1; j>=0; --j) {
					if(((str1[i]-48)+(str2[j]-48))<10) {
						arr+=to_string((str1[i]-48)+(str2[j]-48));
						continue;
					}
					if(i!=0 && j!=0 && (((str1[i]-48)+(str2[j]-48))>=10)) {
						arr+=to_string(((str1[i]-48)+(str2[j]-48))%10);
						string s = to_string(str1[i-1]-48+1);
						str1[i-1]=s[0];
					    continue;
					}
					if(i==0 && size1==size2 && (((str1[0]-48)+(str2[0]-48))>=10)) {
						//cout<<"QWE";
						string s = to_string(((str1[0]-48)+(str2[0]-48))%10);
						arr+=s;
						arr+=to_string(1);
					    break;
					}
					if(i==0 && size1>size2 && (((str1[0]-48)+(str2[0]-48))>=10)) {
						//cout<<"QWE";
						string s = to_string(((str1[0]-48)+(str2[0]-48))%10);
						arr+=s;
						s = to_string((str1[size1-size2-1]-48+1));
						str1[size1-size2-2]=s[0];
					    break;
					}
					if(i==-1 && size1>size2) {
						for(int k=(size1-size2)-1; k>=0; --k) {
							arr+=str1[k];
						}
					}
			    }
		   }
	}
	string trueStr="";
	for(int i=arr.size(); i>=0; --i) {
		trueStr+=arr[i];
	}
	return trueStr;
}

int main() {
	string str1 = "12566110";
	string str2 = "32222889";

	cout<<result(str1,str2)<<endl;

	//to_string(...);
	//int num = stoi(str);
}

/*#include <iostream>

struct true_type{
	static constexpr bool value = true;
};

struct false_type{
	static constexpr bool value = false;
};

struct StructWithoutDefaultConstructor{
	StructWithoutDefaultConstructor()=delete;
};

template <typename ...T>
struct void_type{
	using type = void;
};

template <typename ...T>
using void_type_t = typename void_type<T...>::type;

int func(int a) { return 1; }
int func(StructWithoutDefaultConstructor a) { return 1; }

template <typename T, typename = void>
struct Complex : public false_type{};

template <typename T>
struct Complex<T, void_type_t<decltype(func(std::declval<T>()))>>	: public true_type{};

int main() {
	auto checkInt = Complex<int>::value;
	auto checkStruct = Complex<StructWithoutDefaultConstructor>::value;
	auto checkChar = Complex<void>::value;

	
	std::cout<<checkInt<<" "<<checkStruct<<" "<<checkChar<<std::endl;
}*/