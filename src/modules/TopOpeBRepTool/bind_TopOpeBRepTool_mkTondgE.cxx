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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt2d.hxx>
#include <TopTools_ListOfShape.hxx>
#include <gp_Dir.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <TopOpeBRepTool_mkTondgE.hxx>

void bind_TopOpeBRepTool_mkTondgE(py::module &mod){

py::class_<TopOpeBRepTool_mkTondgE> cls_TopOpeBRepTool_mkTondgE(mod, "TopOpeBRepTool_mkTondgE", "None");

// Constructors
cls_TopOpeBRepTool_mkTondgE.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_mkTondgE::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_mkTondgE::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_mkTondgE::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_mkTondgE::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_mkTondgE::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_mkTondgE::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_mkTondgE.def("Initialize", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &, const TopoDS_Face &, const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_mkTondgE::Initialize, "None", py::arg("dgE"), py::arg("F"), py::arg("uvi"), py::arg("Fi"));
cls_TopOpeBRepTool_mkTondgE.def("SetclE", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetclE, "None", py::arg("clE"));
cls_TopOpeBRepTool_mkTondgE.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)() const) &TopOpeBRepTool_mkTondgE::IsT2d, "None");
cls_TopOpeBRepTool_mkTondgE.def("SetRest", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetRest, "None", py::arg("pari"), py::arg("Ei"));
cls_TopOpeBRepTool_mkTondgE.def("GetAllRest", (Standard_Integer (TopOpeBRepTool_mkTondgE::*)(TopTools_ListOfShape &)) &TopOpeBRepTool_mkTondgE::GetAllRest, "None", py::arg("lEi"));
cls_TopOpeBRepTool_mkTondgE.def("MkTonE", [](TopOpeBRepTool_mkTondgE &self, Standard_Integer & mkT, Standard_Real & par1, Standard_Real & par2){ Standard_Boolean rv = self.MkTonE(mkT, par1, par2); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Real &, Standard_Real &>(rv, mkT, par1, par2); }, "None", py::arg("mkT"), py::arg("par1"), py::arg("par2"));
cls_TopOpeBRepTool_mkTondgE.def("MkTonE", [](TopOpeBRepTool_mkTondgE &self, const TopoDS_Edge & Ei, Standard_Integer & mkT, Standard_Real & par1, Standard_Real & par2){ Standard_Boolean rv = self.MkTonE(Ei, mkT, par1, par2); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Real &, Standard_Real &>(rv, mkT, par1, par2); }, "None", py::arg("Ei"), py::arg("mkT"), py::arg("par1"), py::arg("par2"));

// Enums

}