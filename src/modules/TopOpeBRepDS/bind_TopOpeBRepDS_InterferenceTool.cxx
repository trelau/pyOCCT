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
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepDS_InterferenceTool.hxx>

void bind_TopOpeBRepDS_InterferenceTool(py::module &mod){

py::class_<TopOpeBRepDS_InterferenceTool, std::unique_ptr<TopOpeBRepDS_InterferenceTool>> cls_TopOpeBRepDS_InterferenceTool(mod, "TopOpeBRepDS_InterferenceTool", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_InterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_InterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_InterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_InterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeCurveInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
cls_TopOpeBRepDS_InterferenceTool.def_static("DuplicateCurvePointInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::DuplicateCurvePointInterference, "duplicate I in a new interference with Complement() transition.", py::arg("I"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_InterferenceTool::MakeFaceCurveInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("CurveI"), py::arg("PC"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeSolidSurfaceInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_InterferenceTool::MakeSolidSurfaceInterference, "None", py::arg("Transition"), py::arg("SolidI"), py::arg("SurfaceI"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeVertexInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeVertexInterference, "None", py::arg("Transition"), py::arg("EdgeI"), py::arg("VertexI"), py::arg("VertexIsBound"), py::arg("Config"), py::arg("param"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config)) &TopOpeBRepDS_InterferenceTool::MakeFaceEdgeInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("EdgeI"), py::arg("EdgeIsBound"), py::arg("Config"));
cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"));
cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (void (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"), py::arg("Par"));

// Enums

}