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
#include <TopAbs_ShapeEnum.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopAbs_State.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>

void bind_TopOpeBRepBuild_GTopo(py::module &mod){

py::class_<TopOpeBRepBuild_GTopo, std::unique_ptr<TopOpeBRepBuild_GTopo, Deleter<TopOpeBRepBuild_GTopo>>> cls_TopOpeBRepBuild_GTopo(mod, "TopOpeBRepBuild_GTopo", "None");

// Constructors
cls_TopOpeBRepBuild_GTopo.def(py::init<>());
cls_TopOpeBRepBuild_GTopo.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, const TopOpeBRepDS_Config, const TopOpeBRepDS_Config>(), py::arg("II"), py::arg(""), py::arg("IO"), py::arg("NI"), py::arg("NN"), py::arg("NO"), py::arg("OI"), py::arg("ON"), py::arg("OO"), py::arg("t1"), py::arg("t2"), py::arg("C1"), py::arg("C2"));

// Fields

// Methods
// cls_TopOpeBRepBuild_GTopo.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GTopo::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GTopo::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GTopo::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GTopo::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GTopo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GTopo::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GTopo.def("Reset", (void (TopOpeBRepBuild_GTopo::*)()) &TopOpeBRepBuild_GTopo::Reset, "None");
cls_TopOpeBRepBuild_GTopo.def("Set", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::Set, "None", py::arg("II"), py::arg(""), py::arg("IO"), py::arg("NI"), py::arg("NN"), py::arg("NO"), py::arg("OI"), py::arg("ON"), py::arg("OO"));
cls_TopOpeBRepBuild_GTopo.def("Type", (void (TopOpeBRepBuild_GTopo::*)(TopAbs_ShapeEnum &, TopAbs_ShapeEnum &) const) &TopOpeBRepBuild_GTopo::Type, "None", py::arg("t1"), py::arg("t2"));
cls_TopOpeBRepBuild_GTopo.def("ChangeType", (void (TopOpeBRepBuild_GTopo::*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTopo::ChangeType, "None", py::arg("t1"), py::arg("t2"));
cls_TopOpeBRepBuild_GTopo.def("Config1", (TopOpeBRepDS_Config (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Config1, "None");
cls_TopOpeBRepBuild_GTopo.def("Config2", (TopOpeBRepDS_Config (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Config2, "None");
cls_TopOpeBRepBuild_GTopo.def("ChangeConfig", (void (TopOpeBRepBuild_GTopo::*)(const TopOpeBRepDS_Config, const TopOpeBRepDS_Config)) &TopOpeBRepBuild_GTopo::ChangeConfig, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const TopAbs_State, const TopAbs_State) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const Standard_Integer, const Standard_Integer) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const Standard_Integer) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("II"));
cls_TopOpeBRepBuild_GTopo.def("ChangeValue", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::ChangeValue, "None", py::arg("i1"), py::arg("i2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("ChangeValue", (void (TopOpeBRepBuild_GTopo::*)(const TopAbs_State, const TopAbs_State, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::ChangeValue, "None", py::arg("s1"), py::arg("s2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("GIndex", (Standard_Integer (TopOpeBRepBuild_GTopo::*)(const TopAbs_State) const) &TopOpeBRepBuild_GTopo::GIndex, "None", py::arg("S"));
cls_TopOpeBRepBuild_GTopo.def("GState", (TopAbs_State (TopOpeBRepBuild_GTopo::*)(const Standard_Integer) const) &TopOpeBRepBuild_GTopo::GState, "None", py::arg("I"));
cls_TopOpeBRepBuild_GTopo.def("Index", [](TopOpeBRepBuild_GTopo &self, const Standard_Integer II, Standard_Integer & i1, Standard_Integer & i2){ self.Index(II, i1, i2); return std::tuple<Standard_Integer &, Standard_Integer &>(i1, i2); }, "None", py::arg("II"), py::arg("i1"), py::arg("i2"));
cls_TopOpeBRepBuild_GTopo.def("DumpVal", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &, const TopAbs_State, const TopAbs_State) const) &TopOpeBRepBuild_GTopo::DumpVal, "None", py::arg("OS"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("DumpType", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &) const) &TopOpeBRepBuild_GTopo::DumpType, "None", py::arg("OS"));
cls_TopOpeBRepBuild_GTopo.def_static("DumpSSB_", (void (*)(Standard_OStream &, const TopAbs_State, const TopAbs_State, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::DumpSSB, "None", py::arg("OS"), py::arg("s1"), py::arg("s2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("Dump", [](TopOpeBRepBuild_GTopo &self, Standard_OStream & a0) -> void { return self.Dump(a0); });
cls_TopOpeBRepBuild_GTopo.def("Dump", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &, const Standard_Address) const) &TopOpeBRepBuild_GTopo::Dump, "None", py::arg("OS"), py::arg("s"));
cls_TopOpeBRepBuild_GTopo.def("StatesON", (void (TopOpeBRepBuild_GTopo::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepBuild_GTopo::StatesON, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("IsToReverse1", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::IsToReverse1, "None");
cls_TopOpeBRepBuild_GTopo.def("IsToReverse2", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::IsToReverse2, "None");
cls_TopOpeBRepBuild_GTopo.def("SetReverse", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Boolean)) &TopOpeBRepBuild_GTopo::SetReverse, "None", py::arg("rev"));
cls_TopOpeBRepBuild_GTopo.def("Reverse", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Reverse, "None");
cls_TopOpeBRepBuild_GTopo.def("CopyPermuted", (TopOpeBRepBuild_GTopo (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::CopyPermuted, "None");

// Enums

}