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
#include <GProp_GProps.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Mat.hxx>
#include <gp_Ax1.hxx>
#include <GProp_PrincipalProps.hxx>

void bind_GProp_GProps(py::module &mod){

py::class_<GProp_GProps, std::unique_ptr<GProp_GProps>> cls_GProp_GProps(mod, "GProp_GProps", "Implements a general mechanism to compute the global properties of a 'compound geometric system' in 3d space by composition of the global properties of 'elementary geometric entities' such as (curve, surface, solid, set of points). It is possible to compose the properties of several 'compound geometric systems' too.");

// Constructors
cls_GProp_GProps.def(py::init<>());
cls_GProp_GProps.def(py::init<const gp_Pnt &>(), py::arg("SystemLocation"));

// Fields

// Methods
// cls_GProp_GProps.def_static("operator new_", (void * (*)(size_t)) &GProp_GProps::operator new, "None", py::arg("theSize"));
// cls_GProp_GProps.def_static("operator delete_", (void (*)(void *)) &GProp_GProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_GProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_GProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_GProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_GProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_GProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_GProps.def("Add", [](GProp_GProps &self, const GProp_GProps & a0) -> void { return self.Add(a0); });
cls_GProp_GProps.def("Add", (void (GProp_GProps::*)(const GProp_GProps &, const Standard_Real)) &GProp_GProps::Add, "Either - initializes the global properties retained by this framework from those retained by the framework Item, or - brings together the global properties still retained by this framework with those retained by the framework Item. The value Density, which is 1.0 by default, is used as the density of the system analysed by Item. Sometimes the density will have already been given at the time of construction of the framework Item. This may be the case for example, if Item is a GProp_PGProps framework built to compute the global properties of a set of points ; or another GProp_GProps object which already retains composite global properties. In these cases the real density was perhaps already taken into account at the time of construction of Item. Note that this is not checked: if the density of parts of the system is taken into account two or more times, results of the computation will be false. Notes : - The point relative to which the inertia of Item is computed (i.e. the reference point of Item) may be different from the reference point in this framework. Huygens' theorem is applied automatically to transfer inertia values to the reference point in this framework. - The function Add is used once per component of the system. After that, you use the interrogation functions available to access values computed for the system. - The system whose global properties are already brought together by this framework is referred to as the current system. However, the current system is not retained by this framework, which maintains only its global properties. Exceptions Standard_DomainError if Density is less than or equal to gp::Resolution().", py::arg("Item"), py::arg("Density"));
cls_GProp_GProps.def("Mass", (Standard_Real (GProp_GProps::*)() const) &GProp_GProps::Mass, "Returns the mass of the current system. If no density is attached to the components of the current system the returned value corresponds to : - the total length of the edges of the current system if this framework retains only linear properties, as is the case for example, when using only the LinearProperties function to combine properties of lines from shapes, or - the total area of the faces of the current system if this framework retains only surface properties, as is the case for example, when using only the SurfaceProperties function to combine properties of surfaces from shapes, or - the total volume of the solids of the current system if this framework retains only volume properties, as is the case for example, when using only the VolumeProperties function to combine properties of volumes from solids. Warning A length, an area, or a volume is computed in the current data unit system. The mass of a single object is obtained by multiplying its length, its area or its volume by the given density. You must be consistent with respect to the units used.");
cls_GProp_GProps.def("CentreOfMass", (gp_Pnt (GProp_GProps::*)() const) &GProp_GProps::CentreOfMass, "Returns the center of mass of the current system. If the gravitational field is uniform, it is the center of gravity. The coordinates returned for the center of mass are expressed in the absolute Cartesian coordinate system.");
cls_GProp_GProps.def("MatrixOfInertia", (gp_Mat (GProp_GProps::*)() const) &GProp_GProps::MatrixOfInertia, "returns the matrix of inertia. It is a symmetrical matrix. The coefficients of the matrix are the quadratic moments of inertia.");
cls_GProp_GProps.def("StaticMoments", [](GProp_GProps &self, Standard_Real & Ix, Standard_Real & Iy, Standard_Real & Iz){ self.StaticMoments(Ix, Iy, Iz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Ix, Iy, Iz); }, "Returns Ix, Iy, Iz, the static moments of inertia of the current system; i.e. the moments of inertia about the three axes of the Cartesian coordinate system.", py::arg("Ix"), py::arg("Iy"), py::arg("Iz"));
cls_GProp_GProps.def("MomentOfInertia", (Standard_Real (GProp_GProps::*)(const gp_Ax1 &) const) &GProp_GProps::MomentOfInertia, "computes the moment of inertia of the material system about the axis A.", py::arg("A"));
cls_GProp_GProps.def("PrincipalProperties", (GProp_PrincipalProps (GProp_GProps::*)() const) &GProp_GProps::PrincipalProperties, "Computes the principal properties of inertia of the current system. There is always a set of axes for which the products of inertia of a geometric system are equal to 0; i.e. the matrix of inertia of the system is diagonal. These axes are the principal axes of inertia. Their origin is coincident with the center of mass of the system. The associated moments are called the principal moments of inertia. This function computes the eigen values and the eigen vectors of the matrix of inertia of the system. Results are stored by using a presentation framework of principal properties of inertia (GProp_PrincipalProps object) which may be queried to access the value sought.");
cls_GProp_GProps.def("RadiusOfGyration", (Standard_Real (GProp_GProps::*)(const gp_Ax1 &) const) &GProp_GProps::RadiusOfGyration, "Returns the radius of gyration of the current system about the axis A.", py::arg("A"));

// Enums

}