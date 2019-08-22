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
#include <MoniTool_Stat.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_MoniTool_Stat(py::module &mod){

py::class_<MoniTool_Stat> cls_MoniTool_Stat(mod, "MoniTool_Stat", "This class manages Statistics to be queried asynchronously.");

// Constructors
cls_MoniTool_Stat.def(py::init<>());
cls_MoniTool_Stat.def(py::init<const Standard_CString>(), py::arg("title"));
cls_MoniTool_Stat.def(py::init<const MoniTool_Stat &>(), py::arg("other"));

// Fields

// Methods
// cls_MoniTool_Stat.def_static("operator new_", (void * (*)(size_t)) &MoniTool_Stat::operator new, "None", py::arg("theSize"));
// cls_MoniTool_Stat.def_static("operator delete_", (void (*)(void *)) &MoniTool_Stat::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_Stat::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_Stat.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_Stat::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_Stat::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_Stat::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_Stat.def_static("Current_", (MoniTool_Stat & (*)()) &MoniTool_Stat::Current, "None");
cls_MoniTool_Stat.def("Open", [](MoniTool_Stat &self) -> Standard_Integer { return self.Open(); });
cls_MoniTool_Stat.def("Open", (Standard_Integer (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Open, "Opens a new counter with a starting count of items", py::arg("nb"));
cls_MoniTool_Stat.def("OpenMore", (void (MoniTool_Stat::*)(const Standard_Integer, const Standard_Integer)) &MoniTool_Stat::OpenMore, "Adds more items to be counted by Add... on current level", py::arg("id"), py::arg("nb"));
cls_MoniTool_Stat.def("Add", [](MoniTool_Stat &self) -> void { return self.Add(); });
cls_MoniTool_Stat.def("Add", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Add, "Directly addes items", py::arg("nb"));
cls_MoniTool_Stat.def("AddSub", [](MoniTool_Stat &self) -> void { return self.AddSub(); });
cls_MoniTool_Stat.def("AddSub", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::AddSub, "Declares a count of items to be added later. If a sub-counter is opened, its percentage multiplies this sub-count to compute the percent of current level", py::arg("nb"));
cls_MoniTool_Stat.def("AddEnd", (void (MoniTool_Stat::*)()) &MoniTool_Stat::AddEnd, "Ends the AddSub and cumulates the sub-count to current level");
cls_MoniTool_Stat.def("Close", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Close, "None", py::arg("id"));
cls_MoniTool_Stat.def("Level", (Standard_Integer (MoniTool_Stat::*)() const) &MoniTool_Stat::Level, "None");
cls_MoniTool_Stat.def("Percent", [](MoniTool_Stat &self) -> Standard_Real { return self.Percent(); });
cls_MoniTool_Stat.def("Percent", (Standard_Real (MoniTool_Stat::*)(const Standard_Integer) const) &MoniTool_Stat::Percent, "None", py::arg("fromlev"));

// Enums

}