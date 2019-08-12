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
#include <BRepGProp_Face.hxx>
#include <BRepGProp_Domain.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Handle.hxx>
#include <NCollection_Array1.hxx>
#include <BRepGProp_Gauss.hxx>
#include <gp_Pnt.hxx>
#include <gp_Mat.hxx>
#include <gp_Vec.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>

void bind_BRepGProp_Gauss(py::module &mod){

py::class_<BRepGProp_Gauss, std::unique_ptr<BRepGProp_Gauss, Deleter<BRepGProp_Gauss>>> cls_BRepGProp_Gauss(mod, "BRepGProp_Gauss", "Class performs computing of the global inertia properties of geometric object in 3D space by adaptive and non-adaptive 2D Gauss integration algorithms.");

// Constructors
cls_BRepGProp_Gauss.def(py::init<const BRepGProp_Gauss::BRepGProp_GaussType>(), py::arg("theType"));

// Fields

// Methods
// cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, const BRepGProp_Face & theSurface, const gp_Pnt & theLocation, const Standard_Real [] theCoeff, const Standard_Boolean theIsByPoint, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ self.Compute(theSurface, theLocation, theCoeff, theIsByPoint, theOutMass, theOutGravityCenter, theOutInertia); return theOutMass; }, "Computes the global properties of a solid region of 3D space which can be delimited by the surface and point or surface and plane. Surface can be closed. The method is quick and its precision is enough for many cases of analytical surfaces. Non-adaptive 2D Gauss integration with predefined numbers of Gauss points is used. Numbers of points depend on types of surfaces and curves. Error of the computation is not calculated.", py::arg("theSurface"), py::arg("theLocation"), py::arg("theCoeff"), py::arg("theIsByPoint"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));
cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, const BRepGProp_Face & theSurface, const gp_Pnt & theLocation, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ self.Compute(theSurface, theLocation, theOutMass, theOutGravityCenter, theOutInertia); return theOutMass; }, "Computes the global properties of a surface. Surface can be closed. The method is quick and its precision is enough for many cases of analytical surfaces. Non-adaptive 2D Gauss integration with predefined numbers of Gauss points is used. Numbers of points depend on types of surfaces and curves. Error of the computation is not calculated.", py::arg("theSurface"), py::arg("theLocation"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));
// cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, BRepGProp_Face & theSurface, BRepGProp_Domain & theDomain, const gp_Pnt & theLocation, const Standard_Real [] theCoeff, const Standard_Boolean theIsByPoint, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ self.Compute(theSurface, theDomain, theLocation, theCoeff, theIsByPoint, theOutMass, theOutGravityCenter, theOutInertia); return theOutMass; }, "Computes the global properties of a region of 3D space which can be delimited by the surface and point or surface and plane. Surface can be closed. The method is quick and its precision is enough for many cases of analytical surfaces. Non-adaptive 2D Gauss integration with predefined numbers of Gauss points is used. Numbers of points depend on types of surfaces and curves. Error of the computation is not calculated.", py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theCoeff"), py::arg("theIsByPoint"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));
cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, BRepGProp_Face & theSurface, BRepGProp_Domain & theDomain, const gp_Pnt & theLocation, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ self.Compute(theSurface, theDomain, theLocation, theOutMass, theOutGravityCenter, theOutInertia); return theOutMass; }, "Computes the global properties of a surface. Surface can be closed. The method is quick and its precision is enough for many cases of analytical surfaces. Non-adaptive 2D Gauss integration with predefined numbers of Gauss points is used. Numbers of points depend on types of surfaces and curves. Error of the computation is not calculated.", py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));
// cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, BRepGProp_Face & theSurface, BRepGProp_Domain & theDomain, const gp_Pnt & theLocation, const Standard_Real theEps, const Standard_Real [] theCoeff, const Standard_Boolean theByPoint, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ Standard_Real rv = self.Compute(theSurface, theDomain, theLocation, theEps, theCoeff, theByPoint, theOutMass, theOutGravityCenter, theOutInertia); return std::tuple<Standard_Real, Standard_Real &>(rv, theOutMass); }, "Computes the global properties of the region of 3D space which can be delimited by the surface and point or surface and plane. Adaptive 2D Gauss integration is used. If Epsilon more than 0.001 then algorithm performs non-adaptive integration.", py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theEps"), py::arg("theCoeff"), py::arg("theByPoint"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));
cls_BRepGProp_Gauss.def("Compute", [](BRepGProp_Gauss &self, BRepGProp_Face & theSurface, BRepGProp_Domain & theDomain, const gp_Pnt & theLocation, const Standard_Real theEps, Standard_Real & theOutMass, gp_Pnt & theOutGravityCenter, gp_Mat & theOutInertia){ Standard_Real rv = self.Compute(theSurface, theDomain, theLocation, theEps, theOutMass, theOutGravityCenter, theOutInertia); return std::tuple<Standard_Real, Standard_Real &>(rv, theOutMass); }, "Computes the global properties of the face. Adaptive 2D Gauss integration is used. If Epsilon more than 0.001 then algorithm performs non-adaptive integration.", py::arg("theSurface"), py::arg("theDomain"), py::arg("theLocation"), py::arg("theEps"), py::arg("theOutMass"), py::arg("theOutGravityCenter"), py::arg("theOutInertia"));

// Enums
py::enum_<BRepGProp_Gauss::BRepGProp_GaussType>(cls_BRepGProp_Gauss, "BRepGProp_Gauss_BRepGProp_GaussType", "Describes types of geometric objects. - Vinert is 3D closed region of space delimited with: -- Surface; -- Point and Surface; -- Plane and Surface. - Sinert is face in 3D space.")
	.value("Vinert", BRepGProp_Gauss::BRepGProp_GaussType::Vinert)
	.value("Sinert", BRepGProp_Gauss::BRepGProp_GaussType::Sinert)
	.export_values();

}