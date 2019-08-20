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
#include <Convert_ElementarySurfaceToBSplineSurface.hxx>
#include <Standard.hxx>
#include <gp_Sphere.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_SphereToBSplineSurface.hxx>

void bind_Convert_SphereToBSplineSurface(py::module &mod){

py::class_<Convert_SphereToBSplineSurface, std::unique_ptr<Convert_SphereToBSplineSurface>, Convert_ElementarySurfaceToBSplineSurface> cls_Convert_SphereToBSplineSurface(mod, "Convert_SphereToBSplineSurface", "This algorithm converts a bounded Sphere into a rational B-spline surface. The sphere is a Sphere from package gp. The parametrization of the sphere is P (U, V) = Loc + Radius * Sin(V) * Zdir + Radius * Cos(V) * (Cos(U)*Xdir + Sin(U)*Ydir) where Loc is the center of the sphere Xdir, Ydir and Zdir are the normalized directions of the local cartesian coordinate system of the sphere. The parametrization range is U [0, 2PI] and V [-PI/2, PI/2]. KeyWords : Convert, Sphere, BSplineSurface.");

// Constructors
cls_Convert_SphereToBSplineSurface.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Sph"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Convert_SphereToBSplineSurface.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real>(), py::arg("Sph"), py::arg("Param1"), py::arg("Param2"));
cls_Convert_SphereToBSplineSurface.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Sph"), py::arg("Param1"), py::arg("Param2"), py::arg("UTrim"));
cls_Convert_SphereToBSplineSurface.def(py::init<const gp_Sphere &>(), py::arg("Sph"));

// Fields

// Methods
// cls_Convert_SphereToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Convert_SphereToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Convert_SphereToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Convert_SphereToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Convert_SphereToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Convert_SphereToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Convert_SphereToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Convert_SphereToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_SphereToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_SphereToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_SphereToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Convert_SphereToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}