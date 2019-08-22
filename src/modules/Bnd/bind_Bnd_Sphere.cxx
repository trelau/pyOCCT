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
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Sphere.hxx>

void bind_Bnd_Sphere(py::module &mod){

py::class_<Bnd_Sphere> cls_Bnd_Sphere(mod, "Bnd_Sphere", "This class represents a bounding sphere of a geometric entity (triangle, segment of line or whatever else).");

// Constructors
cls_Bnd_Sphere.def(py::init<>());
cls_Bnd_Sphere.def(py::init<const gp_XYZ &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theCntr"), py::arg("theRad"), py::arg("theU"), py::arg("theV"));

// Fields

// Methods
// cls_Bnd_Sphere.def_static("operator new_", (void * (*)(size_t)) &Bnd_Sphere::operator new, "None", py::arg("theSize"));
// cls_Bnd_Sphere.def_static("operator delete_", (void (*)(void *)) &Bnd_Sphere::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Sphere::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Sphere.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Sphere::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Sphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Sphere::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Sphere.def("U", (Standard_Integer (Bnd_Sphere::*)() const) &Bnd_Sphere::U, "Returns the U parameter on shape");
cls_Bnd_Sphere.def("V", (Standard_Integer (Bnd_Sphere::*)() const) &Bnd_Sphere::V, "Returns the V parameter on shape");
cls_Bnd_Sphere.def("IsValid", (Standard_Boolean (Bnd_Sphere::*)() const) &Bnd_Sphere::IsValid, "Returns validity status, indicating that this sphere corresponds to a real entity");
cls_Bnd_Sphere.def("SetValid", (void (Bnd_Sphere::*)(const Standard_Boolean)) &Bnd_Sphere::SetValid, "None", py::arg("isValid"));
cls_Bnd_Sphere.def("Center", (const gp_XYZ & (Bnd_Sphere::*)() const) &Bnd_Sphere::Center, "Returns center of sphere object");
cls_Bnd_Sphere.def("Radius", (Standard_Real (Bnd_Sphere::*)() const) &Bnd_Sphere::Radius, "Returns the radius value");
cls_Bnd_Sphere.def("Distances", [](Bnd_Sphere &self, const gp_XYZ & theXYZ, Standard_Real & theMin, Standard_Real & theMax){ self.Distances(theXYZ, theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
cls_Bnd_Sphere.def("SquareDistances", [](Bnd_Sphere &self, const gp_XYZ & theXYZ, Standard_Real & theMin, Standard_Real & theMax){ self.SquareDistances(theXYZ, theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
cls_Bnd_Sphere.def("Project", [](Bnd_Sphere &self, const gp_XYZ & theNode, gp_XYZ & theProjNode, Standard_Real & theDist, Standard_Boolean & theInside){ Standard_Boolean rv = self.Project(theNode, theProjNode, theDist, theInside); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, theDist, theInside); }, "Projects a point on entity. Returns true if success", py::arg("theNode"), py::arg("theProjNode"), py::arg("theDist"), py::arg("theInside"));
cls_Bnd_Sphere.def("Distance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const) &Bnd_Sphere::Distance, "None", py::arg("theNode"));
cls_Bnd_Sphere.def("SquareDistance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const) &Bnd_Sphere::SquareDistance, "None", py::arg("theNode"));
cls_Bnd_Sphere.def("Add", (void (Bnd_Sphere::*)(const Bnd_Sphere &)) &Bnd_Sphere::Add, "None", py::arg("theOther"));
cls_Bnd_Sphere.def("IsOut", (Standard_Boolean (Bnd_Sphere::*)(const Bnd_Sphere &) const) &Bnd_Sphere::IsOut, "None", py::arg("theOther"));
cls_Bnd_Sphere.def("IsOut", [](Bnd_Sphere &self, const gp_XYZ & thePnt, Standard_Real & theMaxDist){ Standard_Boolean rv = self.IsOut(thePnt, theMaxDist); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theMaxDist); }, "None", py::arg("thePnt"), py::arg("theMaxDist"));
cls_Bnd_Sphere.def("SquareExtent", (Standard_Real (Bnd_Sphere::*)() const) &Bnd_Sphere::SquareExtent, "None");

// Enums

}