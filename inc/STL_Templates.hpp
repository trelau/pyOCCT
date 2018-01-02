#ifndef __STL_Templates_Header__
#define __STL_Templates_Header__

#include <pyOCCT_Common.hpp>

// List
template <typename TheItemType>
void bind_list(py::object &mod, std::string const &name) {

	py::class_ <std::list<TheItemType>> cls(mod, name.c_str());
	cls.def(py::init<>());
	cls.def("clear", &std::list<TheItemType>::clear, "Clear content.");
	cls.def("size", &std::list<TheItemType>::size, "Return size.");
	cls.def("empty", &std::list<TheItemType>::empty, "Test whether container is empty.");
	cls.def("pop_front", &std::list<TheItemType>::pop_front, "Delete first element.");
	cls.def("pop_back", &std::list<TheItemType>::pop_back, "Delete last element.");
	cls.def("push_front", (void (std::list<TheItemType>::*)(const TheItemType &)) &std::list<TheItemType>::push_front, "Add element at front.");
	cls.def("push_back", (void (std::list<TheItemType>::*)(const TheItemType &)) &std::list<TheItemType>::push_back, "Add element at end.");
	cls.def("front", [](std::list<TheItemType> &self) -> TheItemType {return self.front(); }, "Access first item.");
	cls.def("back", [](std::list<TheItemType> &self) -> TheItemType {return self.back(); }, "Access last item.");
	cls.def("__len__", &std::list<TheItemType>::size);
	cls.def("__iter__", [](const std::list<TheItemType> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

#endif
