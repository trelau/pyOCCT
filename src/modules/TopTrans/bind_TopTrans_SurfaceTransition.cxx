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
#include <TopAbs_State.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TopTrans_Array2OfOrientation.hxx>
#include <TopTrans_SurfaceTransition.hxx>

void bind_TopTrans_SurfaceTransition(py::module &mod){

py::class_<TopTrans_SurfaceTransition> cls_TopTrans_SurfaceTransition(mod, "TopTrans_SurfaceTransition", "This algorithm is used to compute the transition of a 3D surface intersecting a topological surfacic boundary on a 3D curve ( intersection curve ). The boundary is described by a set of faces each face is described by - its support surface, - an orientation defining its matter side. The geometric elements are described locally at the intersection point by a second order development. A surface is described by the normal vector, the principal directions and the principal curvatures. A curve is described by the tangent, the normal and the curvature. The algorithm keeps track of the two faces elements closest to the part of the curve 'before' and 'after' the intersection, these two elements are updated for each new face. The position of the curve can be computed when at least one surface element has been given, this position is 'In','Out' or 'On' for the part of the curve 'Before' or 'After' the intersection.");

// Constructors
cls_TopTrans_SurfaceTransition.def(py::init<>());

// Fields

// Methods
// cls_TopTrans_SurfaceTransition.def_static("operator new_", (void * (*)(size_t)) &TopTrans_SurfaceTransition::operator new, "None", py::arg("theSize"));
// cls_TopTrans_SurfaceTransition.def_static("operator delete_", (void (*)(void *)) &TopTrans_SurfaceTransition::operator delete, "None", py::arg("theAddress"));
// cls_TopTrans_SurfaceTransition.def_static("operator new[]_", (void * (*)(size_t)) &TopTrans_SurfaceTransition::operator new[], "None", py::arg("theSize"));
// cls_TopTrans_SurfaceTransition.def_static("operator delete[]_", (void (*)(void *)) &TopTrans_SurfaceTransition::operator delete[], "None", py::arg("theAddress"));
// cls_TopTrans_SurfaceTransition.def_static("operator new_", (void * (*)(size_t, void *)) &TopTrans_SurfaceTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTrans_SurfaceTransition.def_static("operator delete_", (void (*)(void *, void *)) &TopTrans_SurfaceTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTrans_SurfaceTransition.def("Reset", (void (TopTrans_SurfaceTransition::*)(const gp_Dir &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real)) &TopTrans_SurfaceTransition::Reset, "Initialize a Surface Transition with the local description of the intersection curve and of the reference surface. PREQUESITORY : Norm oriented OUTSIDE 'geometric matter'", py::arg("Tgt"), py::arg("Norm"), py::arg("MaxD"), py::arg("MinD"), py::arg("MaxCurv"), py::arg("MinCurv"));
cls_TopTrans_SurfaceTransition.def("Reset", (void (TopTrans_SurfaceTransition::*)(const gp_Dir &, const gp_Dir &)) &TopTrans_SurfaceTransition::Reset, "Initialize a Surface Transition with the local description of a straight line.", py::arg("Tgt"), py::arg("Norm"));
cls_TopTrans_SurfaceTransition.def("Compare", (void (TopTrans_SurfaceTransition::*)(const Standard_Real, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_SurfaceTransition::Compare, "Add a face element to the boundary.", py::arg("Tole"), py::arg("Norm"), py::arg("MaxD"), py::arg("MinD"), py::arg("MaxCurv"), py::arg("MinCurv"), py::arg("S"), py::arg("O"));
cls_TopTrans_SurfaceTransition.def("Compare", (void (TopTrans_SurfaceTransition::*)(const Standard_Real, const gp_Dir &, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_SurfaceTransition::Compare, "Add a plane or a cylindric face to the boundary.", py::arg("Tole"), py::arg("Norm"), py::arg("S"), py::arg("O"));
cls_TopTrans_SurfaceTransition.def("StateBefore", (TopAbs_State (TopTrans_SurfaceTransition::*)() const) &TopTrans_SurfaceTransition::StateBefore, "Returns the state of the reference surface before the interference, this is the position relative to the surface of a point very close to the intersection on the negative side of the tangent.");
cls_TopTrans_SurfaceTransition.def("StateAfter", (TopAbs_State (TopTrans_SurfaceTransition::*)() const) &TopTrans_SurfaceTransition::StateAfter, "Returns the state of the reference surface after interference, this is the position relative to the surface of a point very close to the intersection on the positive side of the tangent.");
cls_TopTrans_SurfaceTransition.def_static("GetBefore_", (TopAbs_State (*)(const TopAbs_Orientation)) &TopTrans_SurfaceTransition::GetBefore, "None", py::arg("Tran"));
cls_TopTrans_SurfaceTransition.def_static("GetAfter_", (TopAbs_State (*)(const TopAbs_Orientation)) &TopTrans_SurfaceTransition::GetAfter, "None", py::arg("Tran"));

// Enums

}