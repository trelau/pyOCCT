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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_XYZ.hxx>
#include <gp_Mat.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>
#include <gp_Vec.hxx>
#include <gp_Ax3.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Cone.hxx>
#include <gp_XY.hxx>
#include <gp_Mat2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_GTrsf2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp.hxx>

void bind_gp(py::module &mod){

py::class_<gp> cls_gp(mod, "gp", "The geometric processor package, called gp, provides an implementation of entities used : . for algebraic calculation such as 'XYZ' coordinates, 'Mat' matrix . for basis analytic geometry such as Transformations, point, vector, line, plane, axis placement, conics, and elementary surfaces. These entities are defined in 2d and 3d space. All the classes of this package are non-persistent.");

// Constructors

// Fields

// Methods
// cls_gp.def_static("operator new_", (void * (*)(size_t)) &gp::operator new, "None", py::arg("theSize"));
// cls_gp.def_static("operator delete_", (void (*)(void *)) &gp::operator delete, "None", py::arg("theAddress"));
// cls_gp.def_static("operator new[]_", (void * (*)(size_t)) &gp::operator new[], "None", py::arg("theSize"));
// cls_gp.def_static("operator delete[]_", (void (*)(void *)) &gp::operator delete[], "None", py::arg("theAddress"));
// cls_gp.def_static("operator new_", (void * (*)(size_t, void *)) &gp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp.def_static("operator delete_", (void (*)(void *, void *)) &gp::operator delete, "None", py::arg(""), py::arg(""));
cls_gp.def_static("Resolution_", (Standard_Real (*)()) &gp::Resolution, "Method of package gp");
cls_gp.def_static("Origin_", (const gp_Pnt & (*)()) &gp::Origin, "Identifies a Cartesian point with coordinates X = Y = Z = 0.0.0");
cls_gp.def_static("DX_", (const gp_Dir & (*)()) &gp::DX, "Returns a unit vector with the combination (1,0,0)");
cls_gp.def_static("DY_", (const gp_Dir & (*)()) &gp::DY, "Returns a unit vector with the combination (0,1,0)");
cls_gp.def_static("DZ_", (const gp_Dir & (*)()) &gp::DZ, "Returns a unit vector with the combination (0,0,1)");
cls_gp.def_static("OX_", (const gp_Ax1 & (*)()) &gp::OX, "Identifies an axis where its origin is Origin and its unit vector coordinates X = 1.0, Y = Z = 0.0");
cls_gp.def_static("OY_", (const gp_Ax1 & (*)()) &gp::OY, "Identifies an axis where its origin is Origin and its unit vector coordinates Y = 1.0, X = Z = 0.0");
cls_gp.def_static("OZ_", (const gp_Ax1 & (*)()) &gp::OZ, "Identifies an axis where its origin is Origin and its unit vector coordinates Z = 1.0, Y = X = 0.0");
cls_gp.def_static("XOY_", (const gp_Ax2 & (*)()) &gp::XOY, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates Z = 1.0, X = Y =0.0 and X direction coordinates X = 1.0, Y = Z = 0.0");
cls_gp.def_static("ZOX_", (const gp_Ax2 & (*)()) &gp::ZOX, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates Y = 1.0, X = Z =0.0 and X direction coordinates Z = 1.0, X = Y = 0.0");
cls_gp.def_static("YOZ_", (const gp_Ax2 & (*)()) &gp::YOZ, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates X = 1.0, Z = Y =0.0 and X direction coordinates Y = 1.0, X = Z = 0.0 In 2D space");
cls_gp.def_static("Origin2d_", (const gp_Pnt2d & (*)()) &gp::Origin2d, "Identifies a Cartesian point with coordinates X = Y = 0.0");
cls_gp.def_static("DX2d_", (const gp_Dir2d & (*)()) &gp::DX2d, "Returns a unit vector with the combinations (1,0)");
cls_gp.def_static("DY2d_", (const gp_Dir2d & (*)()) &gp::DY2d, "Returns a unit vector with the combinations (0,1)");
cls_gp.def_static("OX2d_", (const gp_Ax2d & (*)()) &gp::OX2d, "Identifies an axis where its origin is Origin2d and its unit vector coordinates are: X = 1.0, Y = 0.0");
cls_gp.def_static("OY2d_", (const gp_Ax2d & (*)()) &gp::OY2d, "Identifies an axis where its origin is Origin2d and its unit vector coordinates are Y = 1.0, X = 0.0");

// Enums

}