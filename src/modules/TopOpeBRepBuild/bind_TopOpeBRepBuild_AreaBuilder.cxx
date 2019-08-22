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
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopOpeBRepBuild_ListOfLoop.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepBuild_LoopEnum.hxx>
#include <TopOpeBRepBuild_ListOfListOfLoop.hxx>
#include <TopOpeBRepBuild_AreaBuilder.hxx>

void bind_TopOpeBRepBuild_AreaBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_AreaBuilder(mod, "TopOpeBRepBuild_AreaBuilder", "The AreaBuilder algorithm is used to reconstruct complex topological objects as Faces or Solids. * Loop is the composite topological object of the boundary. Wire for a Face. Shell for a Solid. * LoopSet is a tool describing the object to build. It gives an iteration on Loops. For each Loop it tells if it is on the boundary or if it is an interference. * LoopClassifier is an algorithm used to test if a Loop is inside another Loop. The result of the reconstruction is an iteration on the reconstructed areas. An area is described by a set of Loops. A AreaBuilder is built with : - a LoopSet describing the object to reconstruct. - a LoopClassifier providing the classification algorithm.");

// Constructors
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<>());
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Fields

// Methods
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_AreaBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_AreaBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_AreaBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_AreaBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_AreaBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_AreaBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_AreaBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_AreaBuilder::InitAreaBuilder, "Sets a AreaBuilder to find the areas on the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_AreaBuilder.def("InitArea", (Standard_Integer (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::InitArea, "Initialize iteration on areas.");
cls_TopOpeBRepBuild_AreaBuilder.def("MoreArea", (Standard_Boolean (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::MoreArea, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("NextArea", (void (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::NextArea, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("InitLoop", (Standard_Integer (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::InitLoop, "Initialize iteration on loops of current Area.");
cls_TopOpeBRepBuild_AreaBuilder.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::MoreLoop, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("NextLoop", (void (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::NextLoop, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("Loop", (const opencascade::handle<TopOpeBRepBuild_Loop> & (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::Loop, "Returns the current Loop in the current area.");
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_Loop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, const opencascade::handle<TopOpeBRepBuild_Loop> & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_Loop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_Loop_TO_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::ADD_Loop_TO_LISTOFLoop, "None", py::arg("L"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_AreaBuilder.def("REM_Loop_FROM_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListIteratorOfListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.REM_Loop_FROM_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("REM_Loop_FROM_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_ListIteratorOfListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::REM_Loop_FROM_LISTOFLoop, "None", py::arg("ITLOL"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2, const Standard_Address a3) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_ListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address, const Standard_Address, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::ADD_LISTOFLoop_TO_LISTOFLoop, "None", py::arg("LOL1"), py::arg("LOL2"), py::arg("s"), py::arg("s1"), py::arg("s2"));

// Enums

}