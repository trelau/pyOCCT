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
#include <TopOpeBRepBuild_AreaBuilder.hxx>
#include <Standard.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>
#include <TopOpeBRepBuild_PaveClassifier.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopOpeBRepBuild_ListOfLoop.hxx>
#include <TopOpeBRepBuild_Area1dBuilder.hxx>

void bind_TopOpeBRepBuild_Area1dBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_Area1dBuilder, std::unique_ptr<TopOpeBRepBuild_Area1dBuilder>, TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_Area1dBuilder(mod, "TopOpeBRepBuild_Area1dBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<>());
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Fields

// Methods
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Area1dBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Area1dBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Area1dBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Area1dBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_Area1dBuilder::InitAreaBuilder, "Sets a Area1dBuilder to find the areas of the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_Loop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, const opencascade::handle<TopOpeBRepBuild_Loop> & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_Loop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_Loop_TO_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::ADD_Loop_TO_LISTOFLoop, "None", py::arg("L"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_Area1dBuilder.def("REM_Loop_FROM_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListIteratorOfListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.REM_Loop_FROM_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("REM_Loop_FROM_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_ListIteratorOfListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::REM_Loop_FROM_LISTOFLoop, "None", py::arg("ITLOL"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2, const Standard_Address a3) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_ListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address, const Standard_Address, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::ADD_LISTOFLoop_TO_LISTOFLoop, "None", py::arg("LOL1"), py::arg("LOL2"), py::arg("s"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_Area1dBuilder.def_static("DumpList_", (void (*)(const TopOpeBRepBuild_ListOfLoop &)) &TopOpeBRepBuild_Area1dBuilder::DumpList, "None", py::arg("L"));

// Enums

}