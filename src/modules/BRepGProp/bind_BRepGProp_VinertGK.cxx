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
#include <BRepGProp_Face.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepGProp_Domain.hxx>
#include <gp_Pln.hxx>
#include <BRepGProp_VinertGK.hxx>

void bind_BRepGProp_VinertGK(py::module &mod){

py::class_<BRepGProp_VinertGK, std::unique_ptr<BRepGProp_VinertGK, Deleter<BRepGProp_VinertGK>>, GProp_GProps> cls_BRepGProp_VinertGK(mod, "BRepGProp_VinertGK", "Computes the global properties of a geometric solid (3D closed region of space) delimited with : - a point and a surface - a plane and a surface");

// Constructors
cls_BRepGProp_VinertGK.def(py::init<>());
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("thePoint"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePoint"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePoint"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pln &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("thePlane"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pln &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pln &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, const gp_Pln &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePlane"), py::arg("theLocation"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &, const Standard_Real>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"));
cls_BRepGProp_VinertGK.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSurface"), py::arg("theDomain"), py::arg("thePlane"), py::arg("theLocation"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));

// Fields

// Methods
// cls_BRepGProp_VinertGK.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_VinertGK::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_VinertGK.def_static("operator delete_", (void (*)(void *)) &BRepGProp_VinertGK::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_VinertGK.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_VinertGK::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_VinertGK.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_VinertGK::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_VinertGK.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_VinertGK::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_VinertGK.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_VinertGK::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_VinertGK.def("SetLocation", (void (BRepGProp_VinertGK::*)(const gp_Pnt &)) &BRepGProp_VinertGK::SetLocation, "Sets the vertex that delimit 3D closed region of space.", py::arg("theLocation"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0) -> Standard_Real { return self.Perform(a0); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const Standard_Real a1) -> Standard_Real { return self.Perform(a0, a1); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const Standard_Real a1, const Standard_Boolean a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the naturally restricted surface and the point VLocation.", py::arg("theSurface"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pnt & a1) -> Standard_Real { return self.Perform(a0, a1); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pnt & a1, const Standard_Real a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pnt & a1, const Standard_Real a2, const Standard_Boolean a3) -> Standard_Real { return self.Perform(a0, a1, a2, a3); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the naturally restricted surface and the point VLocation. The inertia is computed with respect to thePoint.", py::arg("theSurface"), py::arg("thePoint"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1) -> Standard_Real { return self.Perform(a0, a1); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const Standard_Real a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const Standard_Real a2, const Standard_Boolean a3) -> Standard_Real { return self.Perform(a0, a1, a2, a3); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, BRepGProp_Domain &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the surface bounded by the domain and the point VLocation.", py::arg("theSurface"), py::arg("theDomain"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pnt & a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pnt & a2, const Standard_Real a3) -> Standard_Real { return self.Perform(a0, a1, a2, a3); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pnt & a2, const Standard_Real a3, const Standard_Boolean a4) -> Standard_Real { return self.Perform(a0, a1, a2, a3, a4); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the surface bounded by the domain and the point VLocation. The inertia is computed with respect to thePoint.", py::arg("theSurface"), py::arg("theDomain"), py::arg("thePoint"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pln & a1) -> Standard_Real { return self.Perform(a0, a1); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pln & a1, const Standard_Real a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, const gp_Pln & a1, const Standard_Real a2, const Standard_Boolean a3) -> Standard_Real { return self.Perform(a0, a1, a2, a3); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, const gp_Pln &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the naturally restricted surface and the plane.", py::arg("theSurface"), py::arg("thePlane"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pln & a2) -> Standard_Real { return self.Perform(a0, a1, a2); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pln & a2, const Standard_Real a3) -> Standard_Real { return self.Perform(a0, a1, a2, a3); });
cls_BRepGProp_VinertGK.def("Perform", [](BRepGProp_VinertGK &self, BRepGProp_Face & a0, BRepGProp_Domain & a1, const gp_Pln & a2, const Standard_Real a3, const Standard_Boolean a4) -> Standard_Real { return self.Perform(a0, a1, a2, a3, a4); });
cls_BRepGProp_VinertGK.def("Perform", (Standard_Real (BRepGProp_VinertGK::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepGProp_VinertGK::Perform, "Computes the global properties of a region of 3D space delimited with the surface bounded by the domain and the plane.", py::arg("theSurface"), py::arg("theDomain"), py::arg("thePlane"), py::arg("theTolerance"), py::arg("theCGFlag"), py::arg("theIFlag"));
cls_BRepGProp_VinertGK.def("GetErrorReached", (Standard_Real (BRepGProp_VinertGK::*)() const) &BRepGProp_VinertGK::GetErrorReached, "Returns the relative reached computation error.");
// cls_BRepGProp_VinertGK.def("GetAbsolutError", (Standard_Real (BRepGProp_VinertGK::*)() const) &BRepGProp_VinertGK::GetAbsolutError, "Returns the absolut reached computation error.");

// Enums

}