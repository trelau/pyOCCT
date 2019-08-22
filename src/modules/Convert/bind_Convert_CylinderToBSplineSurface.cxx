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
#include <gp_Cylinder.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_CylinderToBSplineSurface.hxx>

void bind_Convert_CylinderToBSplineSurface(py::module &mod){

py::class_<Convert_CylinderToBSplineSurface, Convert_ElementarySurfaceToBSplineSurface> cls_Convert_CylinderToBSplineSurface(mod, "Convert_CylinderToBSplineSurface", "This algorithm converts a bounded cylinder into a rational B-spline surface. The cylinder is a Cylinder from package gp. The parametrization of the cylinder is : P (U, V) = Loc + V * Zdir + Radius * (Xdir*Cos(U) + Ydir*Sin(U)) where Loc is the location point of the cylinder, Xdir, Ydir and Zdir are the normalized directions of the local cartesian coordinate system of the cylinder (Zdir is the direction of the cylinder's axis). The U parametrization range is U [0, 2PI]. KeyWords : Convert, Cylinder, BSplineSurface.");

// Constructors
cls_Convert_CylinderToBSplineSurface.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Cyl"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Convert_CylinderToBSplineSurface.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real>(), py::arg("Cyl"), py::arg("V1"), py::arg("V2"));

// Fields

// Methods
// cls_Convert_CylinderToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Convert_CylinderToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Convert_CylinderToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Convert_CylinderToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Convert_CylinderToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Convert_CylinderToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Convert_CylinderToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Convert_CylinderToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_CylinderToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_CylinderToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_CylinderToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Convert_CylinderToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}