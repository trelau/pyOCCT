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
#include <GProp_GProps.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <GProp_PGProps.hxx>

void bind_GProp_PGProps(py::module &mod){

py::class_<GProp_PGProps, std::unique_ptr<GProp_PGProps, Deleter<GProp_PGProps>>, GProp_GProps> cls_GProp_PGProps(mod, "GProp_PGProps", "A framework for computing the global properties of a set of points. A point mass is attached to each point. The global mass of the system is the sum of each individual mass. By default, the point mass is equal to 1 and the mass of a system composed of N points is equal to N. Warning A framework of this sort provides functions to handle sets of points easily. But, like any GProp_GProps object, by using the Add function, it can theoretically bring together the computed global properties and those of a system more complex than a set of points . The mass of each point and the density of each component of the composed system must be coherent. Note that this coherence cannot be checked. Nonetheless, you are advised to restrict your use of a GProp_PGProps object to a set of points and to create a GProp_GProps object in order to bring together global properties of different systems.");

// Constructors
cls_GProp_PGProps.def(py::init<>());
cls_GProp_PGProps.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Pnts"));
cls_GProp_PGProps.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("Pnts"));
cls_GProp_PGProps.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Pnts"), py::arg("Density"));
cls_GProp_PGProps.def(py::init<const TColgp_Array2OfPnt &, const TColStd_Array2OfReal &>(), py::arg("Pnts"), py::arg("Density"));

// Fields

// Methods
// cls_GProp_PGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_PGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_PGProps.def_static("operator delete_", (void (*)(void *)) &GProp_PGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_PGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_PGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PGProps.def("AddPoint", (void (GProp_PGProps::*)(const gp_Pnt &)) &GProp_PGProps::AddPoint, "Brings together the global properties already retained by this framework with those induced by the point Pnt. Pnt may be the first point of the current system. A point mass is attached to the point Pnt, it is either equal to 1. or to Density.", py::arg("P"));
cls_GProp_PGProps.def("AddPoint", (void (GProp_PGProps::*)(const gp_Pnt &, const Standard_Real)) &GProp_PGProps::AddPoint, "Adds a new point P with its density in the system of points Exceptions Standard_DomainError if the mass value Density is less than gp::Resolution().", py::arg("P"), py::arg("Density"));
cls_GProp_PGProps.def_static("Barycentre_", (gp_Pnt (*)(const TColgp_Array1OfPnt &)) &GProp_PGProps::Barycentre, "Computes the barycentre of a set of points. The density of the points is defaulted to 1.", py::arg("Pnts"));
cls_GProp_PGProps.def_static("Barycentre_", (gp_Pnt (*)(const TColgp_Array2OfPnt &)) &GProp_PGProps::Barycentre, "Computes the barycentre of a set of points. The density of the points is defaulted to 1.", py::arg("Pnts"));
cls_GProp_PGProps.def_static("Barycentre_", [](const TColgp_Array1OfPnt & Pnts, const TColStd_Array1OfReal & Density, Standard_Real & Mass, gp_Pnt & G){ GProp_PGProps::Barycentre(Pnts, Density, Mass, G); return Mass; }, "Computes the barycentre of a set of points. A density is associated with each point.", py::arg("Pnts"), py::arg("Density"), py::arg("Mass"), py::arg("G"));
cls_GProp_PGProps.def_static("Barycentre_", [](const TColgp_Array2OfPnt & Pnts, const TColStd_Array2OfReal & Density, Standard_Real & Mass, gp_Pnt & G){ GProp_PGProps::Barycentre(Pnts, Density, Mass, G); return Mass; }, "Computes the barycentre of a set of points. A density is associated with each point.", py::arg("Pnts"), py::arg("Density"), py::arg("Mass"), py::arg("G"));

// Enums

}