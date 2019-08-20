/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_BitMap.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>

void bind_Interface_BitMap(py::module &mod){

py::class_<Interface_BitMap, std::unique_ptr<Interface_BitMap>> cls_Interface_BitMap(mod, "Interface_BitMap", "A bit map simply allows to associate a boolean flag to each item of a list, such as a list of entities, etc... numbered between 1 and a positive count nbitems");

// Constructors
cls_Interface_BitMap.def(py::init<>());
cls_Interface_BitMap.def(py::init<const Standard_Integer>(), py::arg("nbitems"));
cls_Interface_BitMap.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbitems"), py::arg("resflags"));
cls_Interface_BitMap.def(py::init<const Interface_BitMap &>(), py::arg("other"));
cls_Interface_BitMap.def(py::init<const Interface_BitMap &, const Standard_Boolean>(), py::arg("other"), py::arg("copied"));

// Fields

// Methods
// cls_Interface_BitMap.def_static("operator new_", (void * (*)(size_t)) &Interface_BitMap::operator new, "None", py::arg("theSize"));
// cls_Interface_BitMap.def_static("operator delete_", (void (*)(void *)) &Interface_BitMap::operator delete, "None", py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator new[]_", (void * (*)(size_t)) &Interface_BitMap::operator new[], "None", py::arg("theSize"));
// cls_Interface_BitMap.def_static("operator delete[]_", (void (*)(void *)) &Interface_BitMap::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_BitMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator delete_", (void (*)(void *, void *)) &Interface_BitMap::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_BitMap.def("Initialize", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.Initialize(a0); });
cls_Interface_BitMap.def("Initialize", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer)) &Interface_BitMap::Initialize, "Initialize empty bit by <nbitems> items One flag is defined, n0 0 <resflags> prepares allocation for <resflags> more flags Flags values start at false", py::arg("nbitems"), py::arg("resflags"));
cls_Interface_BitMap.def("Initialize", [](Interface_BitMap &self, const Interface_BitMap & a0) -> void { return self.Initialize(a0); });
cls_Interface_BitMap.def("Initialize", (void (Interface_BitMap::*)(const Interface_BitMap &, const Standard_Boolean)) &Interface_BitMap::Initialize, "Initialize a BitMap from another one", py::arg("other"), py::arg("copied"));
cls_Interface_BitMap.def("Internals", [](Interface_BitMap &self, Standard_Integer & nbitems, Standard_Integer & nbwords, Standard_Integer & nbflags, opencascade::handle<TColStd_HArray1OfInteger> & flags, opencascade::handle<TColStd_HSequenceOfAsciiString> & names){ self.Internals(nbitems, nbwords, nbflags, flags, names); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(nbitems, nbwords, nbflags); }, "Returns internal values, used for copying Flags values start at false", py::arg("nbitems"), py::arg("nbwords"), py::arg("nbflags"), py::arg("flags"), py::arg("names"));
cls_Interface_BitMap.def("Reservate", (void (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::Reservate, "Reservates for a count of more flags", py::arg("moreflags"));
cls_Interface_BitMap.def("SetLength", (void (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::SetLength, "Sets for a new count of items, which can be either less or greater than the former one For new items, their flags start at false", py::arg("nbitems"));
cls_Interface_BitMap.def("AddFlag", [](Interface_BitMap &self) -> Standard_Integer { return self.AddFlag(); });
cls_Interface_BitMap.def("AddFlag", (Standard_Integer (Interface_BitMap::*)(const Standard_CString)) &Interface_BitMap::AddFlag, "Adds a flag, a name can be attached to it Returns its flag number Makes required reservation", py::arg("name"));
cls_Interface_BitMap.def("AddSomeFlags", (Standard_Integer (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::AddSomeFlags, "Adds several flags (<more>) with no name Returns the number of last added flag", py::arg("more"));
cls_Interface_BitMap.def("RemoveFlag", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::RemoveFlag, "Removes a flag given its number. Returns True if done, false if num is out of range", py::arg("num"));
cls_Interface_BitMap.def("SetFlagName", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_CString)) &Interface_BitMap::SetFlagName, "Sets a name for a flag, given its number name can be empty (to erase the name of a flag) Returns True if done, false if : num is out of range, or name non-empty already set to another flag", py::arg("num"), py::arg("name"));
cls_Interface_BitMap.def("NbFlags", (Standard_Integer (Interface_BitMap::*)() const) &Interface_BitMap::NbFlags, "Returns the count of flags (flag 0 not included)");
cls_Interface_BitMap.def("Length", (Standard_Integer (Interface_BitMap::*)() const) &Interface_BitMap::Length, "Returns the count of items (i.e. the length of the bitmap)");
cls_Interface_BitMap.def("FlagName", (Standard_CString (Interface_BitMap::*)(const Standard_Integer) const) &Interface_BitMap::FlagName, "Returns the name recorded for a flag, or an empty string", py::arg("num"));
cls_Interface_BitMap.def("FlagNumber", (Standard_Integer (Interface_BitMap::*)(const Standard_CString) const) &Interface_BitMap::FlagNumber, "Returns the number or a flag given its name, or zero", py::arg("name"));
cls_Interface_BitMap.def("Value", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.Value(a0); });
cls_Interface_BitMap.def("Value", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::Value, "Returns the value (true/false) of a flag, from : - the number of the item - the flag number, by default 0", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("SetValue", [](Interface_BitMap &self, const Standard_Integer a0, const Standard_Boolean a1) -> void { return self.SetValue(a0, a1); });
cls_Interface_BitMap.def("SetValue", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer) const) &Interface_BitMap::SetValue, "Sets a new value for a flag", py::arg("item"), py::arg("val"), py::arg("flag"));
cls_Interface_BitMap.def("SetTrue", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.SetTrue(a0); });
cls_Interface_BitMap.def("SetTrue", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::SetTrue, "Sets a flag to True", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("SetFalse", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.SetFalse(a0); });
cls_Interface_BitMap.def("SetFalse", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::SetFalse, "Sets a flag to False", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("CTrue", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.CTrue(a0); });
cls_Interface_BitMap.def("CTrue", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::CTrue, "Returns the former value for a flag and sets it to True (before : value returned; after : True)", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("CFalse", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.CFalse(a0); });
cls_Interface_BitMap.def("CFalse", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::CFalse, "Returns the former value for a flag and sets it to False (before : value returned; after : False)", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("Init", [](Interface_BitMap &self, const Standard_Boolean a0) -> void { return self.Init(a0); });
cls_Interface_BitMap.def("Init", (void (Interface_BitMap::*)(const Standard_Boolean, const Standard_Integer) const) &Interface_BitMap::Init, "Initialises all the values of Flag Number <flag> to a given value <val>", py::arg("val"), py::arg("flag"));
cls_Interface_BitMap.def("Clear", (void (Interface_BitMap::*)()) &Interface_BitMap::Clear, "Clear all field of bit map");

// Enums

}