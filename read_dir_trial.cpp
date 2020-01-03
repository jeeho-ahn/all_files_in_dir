#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <boost/filesystem.hpp>

typedef std::vector<std::string> stringvec;

struct path_leaf_string
{
	std::string operator()(const boost::filesystem::directory_entry& entry) const
	{
		return entry.path().leaf().string();
	}
};

void read_directory(const std::string& folder, stringvec& v)
{
	boost::filesystem::path p(folder);
	boost::filesystem::directory_iterator start(p);
	boost::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(v), path_leaf_string());
}


int main()
{
	stringvec v;
	std::string folder = "C:/Users/justi/Videos";
	read_directory(folder, v);
	std::copy(v.begin(), v.end(),
		std::ostream_iterator<std::string>(std::cout, "\n"));

	std::cout << "done" << std::endl;
}