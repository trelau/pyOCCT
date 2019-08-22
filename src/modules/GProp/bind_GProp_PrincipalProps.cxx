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
#include <gp_Vec.hxx>
#include <GProp_PrincipalProps.hxx>
#include <GProp_GProps.hxx>
#include <gp_Pnt.hxx>

void bind_GProp_PrincipalProps(py::module &mod){

py::class_<GProp_PrincipalProps> cls_GProp_PrincipalProps(mod, "GProp_PrincipalProps", "A framework to present the principal properties of inertia of a system of which global properties are computed by a GProp_GProps object. There is always a set of axes for which the products of inertia of a geometric system are equal to 0; i.e. the matrix of inertia of the system is diagonal. These axes are the principal axes of inertia. Their origin is coincident with the center of mass of the system. The associated moments are called the principal moments of inertia. This sort of presentation object is created, filled and returned by the function PrincipalProperties for any GProp_GProps object, and can be queried to access the result. Note: The system whose principal properties of inertia are returned by this framework is referred to as the current system. The current system, however, is retained neither by this presentation framework nor by the GProp_GProps object which activates it.");

// Constructors
cls_GProp_PrincipalProps.def(py::init<>());

// Fields

// Methods
// cls_GProp_PrincipalProps.def_static("operator new_", (void * (*)(size_t)) &GProp_PrincipalProps::operator new, "None", py::arg("theSize"));
// cls_GProp_PrincipalProps.def_static("operator delete_", (void (*)(void *)) &GProp_PrincipalProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PrincipalProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_PrincipalProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_PrincipalProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PrincipalProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PrincipalProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PrincipalProps.def("HasSymmetryAxis", (Standard_Boolean (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::HasSymmetryAxis, "returns true if the geometric system has an axis of symmetry. For comparing moments relative tolerance 1.e-10 is used. Usually it is enough for objects, restricted by faces with analitycal geometry.");
cls_GProp_PrincipalProps.def("HasSymmetryAxis", (Standard_Boolean (GProp_PrincipalProps::*)(const Standard_Real) const) &GProp_PrincipalProps::HasSymmetryAxis, "returns true if the geometric system has an axis of symmetry. aTol is relative tolerance for cheking equality of moments If aTol == 0, relative tolerance is ~ 1.e-16 (Epsilon(I))", py::arg("aTol"));
cls_GProp_PrincipalProps.def("HasSymmetryPoint", (Standard_Boolean (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::HasSymmetryPoint, "returns true if the geometric system has a point of symmetry. For comparing moments relative tolerance 1.e-10 is used. Usually it is enough for objects, restricted by faces with analitycal geometry.");
cls_GProp_PrincipalProps.def("HasSymmetryPoint", (Standard_Boolean (GProp_PrincipalProps::*)(const Standard_Real) const) &GProp_PrincipalProps::HasSymmetryPoint, "returns true if the geometric system has a point of symmetry. aTol is relative tolerance for cheking equality of moments If aTol == 0, relative tolerance is ~ 1.e-16 (Epsilon(I))", py::arg("aTol"));
cls_GProp_PrincipalProps.def("Moments", [](GProp_PrincipalProps &self, Standard_Real & Ixx, Standard_Real & Iyy, Standard_Real & Izz){ self.Moments(Ixx, Iyy, Izz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Ixx, Iyy, Izz); }, "Ixx, Iyy and Izz return the principal moments of inertia in the current system. Notes : - If the current system has an axis of symmetry, two of the three values Ixx, Iyy and Izz are equal. They indicate which eigen vectors define an infinity of axes of principal inertia. - If the current system has a center of symmetry, Ixx, Iyy and Izz are equal.", py::arg("Ixx"), py::arg("Iyy"), py::arg("Izz"));
cls_GProp_PrincipalProps.def("FirstAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::FirstAxisOfInertia, "returns the first axis of inertia.");
cls_GProp_PrincipalProps.def("SecondAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::SecondAxisOfInertia, "returns the second axis of inertia.");
cls_GProp_PrincipalProps.def("ThirdAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::ThirdAxisOfInertia, "returns the third axis of inertia. This and the above functions return the first, second or third eigen vector of the matrix of inertia of the current system. The first, second and third principal axis of inertia pass through the center of mass of the current system. They are respectively parallel to these three eigen vectors. Note that: - If the current system has an axis of symmetry, any axis is an axis of principal inertia if it passes through the center of mass of the system, and runs parallel to a linear combination of the two eigen vectors of the matrix of inertia, corresponding to the two eigen values which are equal. If the current system has a center of symmetry, any axis passing through the center of mass of the system is an axis of principal inertia. Use the functions HasSymmetryAxis and HasSymmetryPoint to check these particular cases, where the returned eigen vectors define an infinity of principal axis of inertia. - The Moments function can be used to know which of the three eigen vectors corresponds to the two eigen values which are equal.");
cls_GProp_PrincipalProps.def("RadiusOfGyration", [](GProp_PrincipalProps &self, Standard_Real & Rxx, Standard_Real & Ryy, Standard_Real & Rzz){ self.RadiusOfGyration(Rxx, Ryy, Rzz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Rxx, Ryy, Rzz); }, "Returns the principal radii of gyration Rxx, Ryy and Rzz are the radii of gyration of the current system about its three principal axes of inertia. Note that: - If the current system has an axis of symmetry, two of the three values Rxx, Ryy and Rzz are equal. - If the current system has a center of symmetry, Rxx, Ryy and Rzz are equal.", py::arg("Rxx"), py::arg("Ryy"), py::arg("Rzz"));

// Enums

}