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
#include <gp_Cone.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_ConeToBSplineSurface.hxx>

void bind_Convert_ConeToBSplineSurface(py::module &mod){

py::class_<Convert_ConeToBSplineSurface, std::unique_ptr<Convert_ConeToBSplineSurface, Deleter<Convert_ConeToBSplineSurface>>, Convert_ElementarySurfaceToBSplineSurface> cls_Convert_ConeToBSplineSurface(mod, "Convert_ConeToBSplineSurface", "This algorithm converts a bounded Cone into a rational B-spline surface. The cone a Cone from package gp. Its parametrization is : P (U, V) = Loc + V * Zdir + (R + V*Tan(Ang)) * (Cos(U)*Xdir + Sin(U)*Ydir) where Loc is the location point of the cone, Xdir, Ydir and Zdir are the normalized directions of the local cartesian coordinate system of the cone (Zdir is the direction of the Cone's axis) , Ang is the cone semi-angle. The U parametrization range is [0, 2PI]. KeyWords : Convert, Cone, BSplineSurface.");

// Constructors
cls_Convert_ConeToBSplineSurface.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Convert_ConeToBSplineSurface.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("V1"), py::arg("V2"));

// Fields

// Methods
// cls_Convert_ConeToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Convert_ConeToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Convert_ConeToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Convert_ConeToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Convert_ConeToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Convert_ConeToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Convert_ConeToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Convert_ConeToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_ConeToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_ConeToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_ConeToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Convert_ConeToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}