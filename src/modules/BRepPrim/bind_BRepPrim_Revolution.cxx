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
#include <BRepPrim_OneAxis.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepPrim_Revolution.hxx>

void bind_BRepPrim_Revolution(py::module &mod){

py::class_<BRepPrim_Revolution, std::unique_ptr<BRepPrim_Revolution>, BRepPrim_OneAxis> cls_BRepPrim_Revolution(mod, "BRepPrim_Revolution", "Implement the OneAxis algoritm for a revolution surface.");

// Constructors
cls_BRepPrim_Revolution.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("A"), py::arg("VMin"), py::arg("VMax"), py::arg("M"), py::arg("PM"));

// Fields

// Methods
// cls_BRepPrim_Revolution.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_Revolution::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_Revolution.def_static("operator delete_", (void (*)(void *)) &BRepPrim_Revolution::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_Revolution.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_Revolution::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_Revolution.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_Revolution::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_Revolution.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_Revolution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_Revolution.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_Revolution::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrim_Revolution.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Revolution::*)() const) &BRepPrim_Revolution::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");
cls_BRepPrim_Revolution.def("MakeEmptyMeridianEdge", (TopoDS_Edge (BRepPrim_Revolution::*)(const Standard_Real) const) &BRepPrim_Revolution::MakeEmptyMeridianEdge, "Returns an edge with a 3D curve made from the meridian in the XZ plane rotated by <Ang> around the Z-axis. Ang may be 0 or myAngle.", py::arg("Ang"));
cls_BRepPrim_Revolution.def("MeridianValue", (gp_Pnt2d (BRepPrim_Revolution::*)(const Standard_Real) const) &BRepPrim_Revolution::MeridianValue, "Returns the meridian point at parameter <V> in the plane XZ.", py::arg("V"));
cls_BRepPrim_Revolution.def("SetMeridianPCurve", (void (BRepPrim_Revolution::*)(TopoDS_Edge &, const TopoDS_Face &) const) &BRepPrim_Revolution::SetMeridianPCurve, "Sets the parametric urve of the edge <E> in the face <F> to be the 2d representation of the meridian.", py::arg("E"), py::arg("F"));

// Enums

}