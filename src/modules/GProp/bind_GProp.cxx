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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Mat.hxx>
#include <GProp_GProps.hxx>
#include <GProp_PGProps.hxx>
#include <GProp_CelGProps.hxx>
#include <GProp_SelGProps.hxx>
#include <GProp_VelGProps.hxx>
#include <GProp_PrincipalProps.hxx>
#include <GProp_PEquation.hxx>
#include <GProp.hxx>

void bind_GProp(py::module &mod){

py::class_<GProp, std::unique_ptr<GProp, Deleter<GProp>>> cls_GProp(mod, "GProp", "This package defines algorithmes to compute the global properties of a set of points, a curve, a surface, a solid (non infinite region of space delimited with geometric entities), a compound geometric system (heterogeneous composition of the previous entities).");

// Constructors

// Fields

// Methods
// cls_GProp.def_static("operator new_", (void * (*)(size_t)) &GProp::operator new, "None", py::arg("theSize"));
// cls_GProp.def_static("operator delete_", (void (*)(void *)) &GProp::operator delete, "None", py::arg("theAddress"));
// cls_GProp.def_static("operator new[]_", (void * (*)(size_t)) &GProp::operator new[], "None", py::arg("theSize"));
// cls_GProp.def_static("operator delete[]_", (void (*)(void *)) &GProp::operator delete[], "None", py::arg("theAddress"));
// cls_GProp.def_static("operator new_", (void * (*)(size_t, void *)) &GProp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp.def_static("operator delete_", (void (*)(void *, void *)) &GProp::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp.def_static("HOperator_", (void (*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, gp_Mat &)) &GProp::HOperator, "methods of package Computes the matrix Operator, referred to as the 'Huyghens Operator' of a geometric system at the point Q of the space, using the following data : - Mass, i.e. the mass of the system, - G, the center of mass of the system. The 'Huyghens Operator' is used to compute Inertia/Q, the matrix of inertia of the system at the point Q using Huyghens' theorem : Inertia/Q = Inertia/G + HOperator (Q, G, Mass) where Inertia/G is the matrix of inertia of the system relative to its center of mass as returned by the function MatrixOfInertia on any GProp_GProps object.", py::arg("G"), py::arg("Q"), py::arg("Mass"), py::arg("Operator"));

// Enums

}