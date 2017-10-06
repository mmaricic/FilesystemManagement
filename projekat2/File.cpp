#include "File.h"
#include <queue>

time_t File::getTime(){
	path PATH(p);
	return last_write_time(PATH);
}

long double File::getSize() const{
	if (!is_directory(p)) return file_size(p);
	queue<string> q;
	long double size = 0;
	q.push(p);
	while (!q.empty()){
		string path = q.front();
		q.pop();
		if (is_directory(path)){
			for (auto i = directory_iterator(path); i != directory_iterator(); i++)
				q.push(i->path().string());
		}
		else size += static_cast<long double>(file_size(path));
	}
	return size;
}