#include "FileSelectionDerived.h"

bool FileSizePredicate::operator()(File &file){
	if (range)
		return ((file.getSize() >= minSize) && (file.getSize() <= maxSize));
	return file.getSize() == minSize;
}