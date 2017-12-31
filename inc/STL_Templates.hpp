#ifndef __STL_Templates_Header__
#define __STL_Templates_Header__

#include <pyOCCT_Common.hpp>

// List
template <typename TheType, typename TheItemType>
void bind_list(py::object &mod, std::string const &name) {

	py::class_ <TheType> cls(mod, name.c_str());
	cls.def(py::init<>());
	cls.def("clear", &TheType::clear);
	cls.def("size", &TheType::size);
	cls.def("append", (void (TheType::*)(const TheItemType &)) &TheType::push_back);
	cls.def("__len__", &TheType::size);
	cls.def("__iter__", [](const TheType &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// List of list
template <typename TheType, typename TheItemType>
void bind_list_of_list(py::object &mod, std::string const &name) {

	py::class_ <TheType> cls(mod, name.c_str());
	cls.def(py::init<>());
	cls.def("clear", &TheType::clear);
	cls.def("size", &TheType::size);
	cls.def("append", (void (TheType::*)(const std::list<TheItemType> &)) &TheType::push_back);
	cls.def("__len__", &TheType::size);
	cls.def("__iter__", [](const TheType &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

#endif