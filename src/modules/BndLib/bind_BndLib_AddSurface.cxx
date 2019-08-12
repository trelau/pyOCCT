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
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <BndLib_AddSurface.hxx>

void bind_BndLib_AddSurface(py::module &mod){

py::class_<BndLib_AddSurface, std::unique_ptr<BndLib_AddSurface, Deleter<BndLib_AddSurface>>> cls_BndLib_AddSurface(mod, "BndLib_AddSurface", "computes the box from a surface Functions to add a surface to a bounding box. The surface is defined from a Geom surface.");

// Constructors

// Fields

// Methods
// cls_BndLib_AddSurface.def_static("operator new_", (void * (*)(size_t)) &BndLib_AddSurface::operator new, "None", py::arg("theSize"));
// cls_BndLib_AddSurface.def_static("operator delete_", (void (*)(void *)) &BndLib_AddSurface::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_AddSurface::operator new[], "None", py::arg("theSize"));
// cls_BndLib_AddSurface.def_static("operator delete[]_", (void (*)(void *)) &BndLib_AddSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_AddSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_AddSurface.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_AddSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_AddSurface.def_static("Add_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::Add, "Adds to the bounding box B the surface S B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the surface S is used to include it in the bounding box B: - an exact representation if S is built from a plane, a cylinder, a cone, a sphere or a torus, - the poles of the surface if S is built from a Bezier surface or a BSpline surface, - the points of an approximation of the surface S in cases other than offset surfaces; - in the case of an offset surface, the basis surface is first included according to the previous rules; then the bounding box is enlarged by the offset value. Warning Do not use these functions to add a non-finite surface to the bounding box B. If UMin, UMax, VMin or VMax is an infinite value B will become WholeSpace. S is an adapted surface, that is, an object which is an interface between: - the services provided by a surface from the package Geom - and those required of the surface by the computation algorithm. The adapted surface is created in the following way: Handle(Geom_Surface) mysurface = ... ; GeomAdaptor_Surface S(mysurface); The bounding box B is then enlarged by adding this surface: Bnd_Box B; // ... Standard_Real Tol = ... ; AddSurface::Add ( S, Tol, B );", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("Add_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::Add, "Adds to the bounding box B the surface S the patch of the surface S limited in the u parametric direction by the two parameter values UMin, UMax, and in the v parametric direction by the two parameter values VMin, VMax. Note: depending on the type of curve, one of the following representations of the surface S is used to include it in the bounding box B: - an exact representation if S is built from a plane, a cylinder, a cone, a sphere or a torus, - the poles of the surface if S is built from a Bezier surface or a BSpline surface, - the points of an approximation of the surface S in cases other than offset surfaces; - in the case of an offset surface, the basis surface is first included according to the previous rules; then the bounding box is enlarged by the offset value. Warning Do not use these functions to add a non-finite surface to the bounding box B. If UMin, UMax, VMin or VMax is an infinite value B will become WholeSpace. S is an adapted surface, that is, an object which is an interface between: - the services provided by a surface from the package Geom - and those required of the surface by the computation algorithm. The adapted surface is created in the following way: Handle(Geom_Surface) mysurface = ... ; GeomAdaptor_Surface S(mysurface); The bounding box B is then enlarged by adding this surface: Bnd_Box B; // ... Standard_Real Tol = ... ; AddSurface::Add ( S, Tol, B );", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddOptimal_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddOptimal, "Adds the surface S to the bounding box B. This algorith builds precise bounding box", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddOptimal_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddOptimal, "None", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib_AddSurface.def_static("AddGenSurf_", (void (*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_AddSurface::AddGenSurf, "Adds to the bounding box B the surface S using numerical minimization algorithms This method is used in AddOptimal for not analytical surfaces and torus. if Tol < Precision::Confusion(), Precision::Confusion is used as computation tolerance", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));

// Enums

}