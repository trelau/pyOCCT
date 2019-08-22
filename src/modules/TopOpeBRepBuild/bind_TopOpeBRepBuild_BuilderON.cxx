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
#include <TopOpeBRepBuild_WireEdgeSet.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>
#include <TopOpeBRepBuild_Builder.hxx>
#include <Standard.hxx>
#include <TopOpeBRepBuild_PBuilder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepBuild_PGTopo.hxx>
#include <TopOpeBRepTool_Plos.hxx>
#include <TopOpeBRepBuild_PWireEdgeSet.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepBuild_BuilderON.hxx>

void bind_TopOpeBRepBuild_BuilderON(py::module &mod){

py::class_<TopOpeBRepBuild_BuilderON> cls_TopOpeBRepBuild_BuilderON(mod, "TopOpeBRepBuild_BuilderON", "None");

// Constructors
cls_TopOpeBRepBuild_BuilderON.def(py::init<>());
cls_TopOpeBRepBuild_BuilderON.def(py::init<const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &>(), py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));

// Fields

// Methods
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BuilderON::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BuilderON::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BuilderON::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BuilderON::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BuilderON::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BuilderON::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BuilderON.def("Perform", (void (TopOpeBRepBuild_BuilderON::*)(const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &)) &TopOpeBRepBuild_BuilderON::Perform, "None", py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONCheckI", (Standard_Boolean (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepBuild_BuilderON::GFillONCheckI, "None", py::arg("I"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONPartsWES1", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepBuild_BuilderON::GFillONPartsWES1, "None", py::arg("I"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONPartsWES2", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepBuild_BuilderON::GFillONPartsWES2, "None", py::arg("I"), py::arg("EspON"));
cls_TopOpeBRepBuild_BuilderON.def("Perform2d", (void (TopOpeBRepBuild_BuilderON::*)(const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &)) &TopOpeBRepBuild_BuilderON::Perform2d, "None", py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONParts2dWES2", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepBuild_BuilderON::GFillONParts2dWES2, "None", py::arg("I"), py::arg("EspON"));

// Enums

}