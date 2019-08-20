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
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <TopCnx_EdgeFaceTransition.hxx>

void bind_TopCnx_EdgeFaceTransition(py::module &mod){

py::class_<TopCnx_EdgeFaceTransition, std::unique_ptr<TopCnx_EdgeFaceTransition>> cls_TopCnx_EdgeFaceTransition(mod, "TopCnx_EdgeFaceTransition", "TheEdgeFaceTransition is an algorithm to compute the cumulated transition for interferences on an edge.");

// Constructors
cls_TopCnx_EdgeFaceTransition.def(py::init<>());

// Fields

// Methods
// cls_TopCnx_EdgeFaceTransition.def_static("operator new_", (void * (*)(size_t)) &TopCnx_EdgeFaceTransition::operator new, "None", py::arg("theSize"));
// cls_TopCnx_EdgeFaceTransition.def_static("operator delete_", (void (*)(void *)) &TopCnx_EdgeFaceTransition::operator delete, "None", py::arg("theAddress"));
// cls_TopCnx_EdgeFaceTransition.def_static("operator new[]_", (void * (*)(size_t)) &TopCnx_EdgeFaceTransition::operator new[], "None", py::arg("theSize"));
// cls_TopCnx_EdgeFaceTransition.def_static("operator delete[]_", (void (*)(void *)) &TopCnx_EdgeFaceTransition::operator delete[], "None", py::arg("theAddress"));
// cls_TopCnx_EdgeFaceTransition.def_static("operator new_", (void * (*)(size_t, void *)) &TopCnx_EdgeFaceTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopCnx_EdgeFaceTransition.def_static("operator delete_", (void (*)(void *, void *)) &TopCnx_EdgeFaceTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopCnx_EdgeFaceTransition.def("Reset", (void (TopCnx_EdgeFaceTransition::*)(const gp_Dir &, const gp_Dir &, const Standard_Real)) &TopCnx_EdgeFaceTransition::Reset, "Initialize the algorithm with the local description of the edge.", py::arg("Tgt"), py::arg("Norm"), py::arg("Curv"));
cls_TopCnx_EdgeFaceTransition.def("Reset", (void (TopCnx_EdgeFaceTransition::*)(const gp_Dir &)) &TopCnx_EdgeFaceTransition::Reset, "Initialize the algorithm with a linear Edge.", py::arg("Tgt"));
cls_TopCnx_EdgeFaceTransition.def("AddInterference", (void (TopCnx_EdgeFaceTransition::*)(const Standard_Real, const gp_Dir &, const gp_Dir &, const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation)) &TopCnx_EdgeFaceTransition::AddInterference, "Add a curve element to the boundary. Or is the orientation of the interference on the boundary curve. Tr is the transition of the interference. BTr is the boundary transition of the interference.", py::arg("Tole"), py::arg("Tang"), py::arg("Norm"), py::arg("Curv"), py::arg("Or"), py::arg("Tr"), py::arg("BTr"));
cls_TopCnx_EdgeFaceTransition.def("Transition", (TopAbs_Orientation (TopCnx_EdgeFaceTransition::*)() const) &TopCnx_EdgeFaceTransition::Transition, "Returns the current cumulated transition.");
cls_TopCnx_EdgeFaceTransition.def("BoundaryTransition", (TopAbs_Orientation (TopCnx_EdgeFaceTransition::*)() const) &TopCnx_EdgeFaceTransition::BoundaryTransition, "Returns the current cumulated BoundaryTransition.");

// Enums

}