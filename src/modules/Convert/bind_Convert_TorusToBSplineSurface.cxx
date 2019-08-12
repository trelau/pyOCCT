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
#include <gp_Torus.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_TorusToBSplineSurface.hxx>

void bind_Convert_TorusToBSplineSurface(py::module &mod){

py::class_<Convert_TorusToBSplineSurface, std::unique_ptr<Convert_TorusToBSplineSurface, Deleter<Convert_TorusToBSplineSurface>>, Convert_ElementarySurfaceToBSplineSurface> cls_Convert_TorusToBSplineSurface(mod, "Convert_TorusToBSplineSurface", "This algorithm converts a bounded Torus into a rational B-spline surface. The torus is a Torus from package gp. The parametrization of the torus is : P (U, V) = Loc + MinorRadius * Sin(V) * Zdir + (MajorRadius+MinorRadius*Cos(V)) * (Cos(U)*Xdir + Sin(U)*Ydir) where Loc is the center of the torus, Xdir, Ydir and Zdir are the normalized directions of the local cartesian coordinate system of the Torus. The parametrization range is U [0, 2PI], V [0, 2PI]. KeyWords : Convert, Torus, BSplineSurface.");

// Constructors
cls_Convert_TorusToBSplineSurface.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("T"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Convert_TorusToBSplineSurface.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real>(), py::arg("T"), py::arg("Param1"), py::arg("Param2"));
cls_Convert_TorusToBSplineSurface.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("T"), py::arg("Param1"), py::arg("Param2"), py::arg("UTrim"));
cls_Convert_TorusToBSplineSurface.def(py::init<const gp_Torus &>(), py::arg("T"));

// Fields

// Methods
// cls_Convert_TorusToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Convert_TorusToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Convert_TorusToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Convert_TorusToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Convert_TorusToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Convert_TorusToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Convert_TorusToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Convert_TorusToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_TorusToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_TorusToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_TorusToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Convert_TorusToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}