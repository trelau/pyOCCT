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
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_TKI.hxx>

void bind_TopOpeBRepDS_TKI(py::module &mod){

py::class_<TopOpeBRepDS_TKI, std::unique_ptr<TopOpeBRepDS_TKI, Deleter<TopOpeBRepDS_TKI>>> cls_TopOpeBRepDS_TKI(mod, "TopOpeBRepDS_TKI", "None");

// Constructors
cls_TopOpeBRepDS_TKI.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_TKI.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_TKI::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_TKI::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_TKI::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_TKI::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_TKI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_TKI::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_TKI.def("Clear", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Clear, "None");
cls_TopOpeBRepDS_TKI.def("FillOnGeometry", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnGeometry, "None", py::arg("L"));
cls_TopOpeBRepDS_TKI.def("FillOnSupport", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnSupport, "None", py::arg("L"));
cls_TopOpeBRepDS_TKI.def("IsBound", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::IsBound, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::Interferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::ChangeInterferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("HasInterferences", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::HasInterferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"), py::arg("HI"));
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self) -> void { return self.DumpTKIIterator(); });
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self, const TCollection_AsciiString & a0) -> void { return self.DumpTKIIterator(a0); });
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", (void (TopOpeBRepDS_TKI::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS_TKI::DumpTKIIterator, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepDS_TKI.def("Init", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Init, "None");
cls_TopOpeBRepDS_TKI.def("More", (Standard_Boolean (TopOpeBRepDS_TKI::*)() const) &TopOpeBRepDS_TKI::More, "None");
cls_TopOpeBRepDS_TKI.def("Next", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Next, "None");
cls_TopOpeBRepDS_TKI.def("Value", [](TopOpeBRepDS_TKI &self, TopOpeBRepDS_Kind & K, Standard_Integer & G){ const TopOpeBRepDS_ListOfInterference & rv = self.Value(K, G); return std::tuple<const TopOpeBRepDS_ListOfInterference &, Standard_Integer &>(rv, G); }, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("ChangeValue", [](TopOpeBRepDS_TKI &self, TopOpeBRepDS_Kind & K, Standard_Integer & G){ TopOpeBRepDS_ListOfInterference & rv = self.ChangeValue(K, G); return std::tuple<TopOpeBRepDS_ListOfInterference &, Standard_Integer &>(rv, G); }, "None", py::arg("K"), py::arg("G"));

// Enums

}