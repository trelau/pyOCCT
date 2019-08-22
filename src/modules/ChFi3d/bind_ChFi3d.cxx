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
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFi3d_Builder.hxx>
#include <ChFi3d_ChBuilder.hxx>
#include <ChFi3d_FilBuilder.hxx>
#include <ChFi3d_SearchSing.hxx>
#include <ChFi3d.hxx>

void bind_ChFi3d(py::module &mod){

py::class_<ChFi3d> cls_ChFi3d(mod, "ChFi3d", "creation of spatial fillets on a solid.");

// Constructors

// Fields

// Methods
// cls_ChFi3d.def_static("operator new_", (void * (*)(size_t)) &ChFi3d::operator new, "None", py::arg("theSize"));
// cls_ChFi3d.def_static("operator delete_", (void (*)(void *)) &ChFi3d::operator delete, "None", py::arg("theAddress"));
// cls_ChFi3d.def_static("operator new[]_", (void * (*)(size_t)) &ChFi3d::operator new[], "None", py::arg("theSize"));
// cls_ChFi3d.def_static("operator delete[]_", (void (*)(void *)) &ChFi3d::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi3d.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi3d.def_static("operator delete_", (void (*)(void *, void *)) &ChFi3d::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi3d.def_static("ConcaveSide_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, const TopoDS_Edge &, TopAbs_Orientation &, TopAbs_Orientation &)) &ChFi3d::ConcaveSide, "Returns Reversed in Or1 and(or) Or2 if the concave edge defined by the interior of faces F1 and F2, in the neighbourhood of their boundary E is of the edge opposite to the normal of their surface support. The orientation of faces is not taken into consideration in the calculation. The function returns 0 if the calculation fails (tangence), if not, it returns the number of choice of the fillet or chamfer corresponding to the orientations calculated and to the tangent to the guide line read in E.", py::arg("S1"), py::arg("S2"), py::arg("E"), py::arg("Or1"), py::arg("Or2"));
cls_ChFi3d.def_static("NextSide_", (Standard_Integer (*)(TopAbs_Orientation &, TopAbs_Orientation &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Integer)) &ChFi3d::NextSide, "Same as ConcaveSide, but the orientations are logically deduced from the result of the call of ConcaveSide on the first pair of faces of the fillet or chamnfer.", py::arg("Or1"), py::arg("Or2"), py::arg("OrSave1"), py::arg("OrSave2"), py::arg("ChoixSauv"));
cls_ChFi3d.def_static("NextSide_", (void (*)(TopAbs_Orientation &, const TopAbs_Orientation, const TopAbs_Orientation)) &ChFi3d::NextSide, "Same as the other NextSide, but the calculation is done on an edge only.", py::arg("Or"), py::arg("OrSave"), py::arg("OrFace"));
cls_ChFi3d.def_static("SameSide_", (Standard_Boolean (*)(const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation)) &ChFi3d::SameSide, "Enables to determine while processing an angle, if two fillets or chamfers constituting a face have identic or opposed concave edges.", py::arg("Or"), py::arg("OrSave1"), py::arg("OrSave2"), py::arg("OrFace1"), py::arg("OrFace2"));

// Enums

}