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
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Line.hxx>
#include <GeomPlate_SequenceOfAij.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>

void bind_GeomPlate_BuildAveragePlane(py::module &mod){

py::class_<GeomPlate_BuildAveragePlane> cls_GeomPlate_BuildAveragePlane(mod, "GeomPlate_BuildAveragePlane", "This class computes an average inertial plane with an array of points. Computes the initial surface (average plane) in the cases when the initial surface is not given.");

// Constructors
cls_GeomPlate_BuildAveragePlane.def(py::init<const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Pts"), py::arg("NbBoundPoints"), py::arg("Tol"), py::arg("POption"), py::arg("NOption"));
cls_GeomPlate_BuildAveragePlane.def(py::init<const TColgp_SequenceOfVec &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("Normals"), py::arg("Pts"));

// Fields

// Methods
// cls_GeomPlate_BuildAveragePlane.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_BuildAveragePlane::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete_", (void (*)(void *)) &GeomPlate_BuildAveragePlane::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_BuildAveragePlane::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_BuildAveragePlane::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_BuildAveragePlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_BuildAveragePlane.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_BuildAveragePlane::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_BuildAveragePlane.def("Plane", (opencascade::handle<Geom_Plane> (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::Plane, "Return the average Plane.");
cls_GeomPlate_BuildAveragePlane.def("Line", (opencascade::handle<Geom_Line> (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::Line, "Return a Line when 2 eigenvalues are null.");
cls_GeomPlate_BuildAveragePlane.def("IsPlane", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::IsPlane, "return OK if is a plane.");
cls_GeomPlate_BuildAveragePlane.def("IsLine", (Standard_Boolean (GeomPlate_BuildAveragePlane::*)() const) &GeomPlate_BuildAveragePlane::IsLine, "return OK if is a line.");
cls_GeomPlate_BuildAveragePlane.def("MinMaxBox", [](GeomPlate_BuildAveragePlane &self, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ self.MinMaxBox(Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Umin, Umax, Vmin, Vmax); }, "computes the minimal box to include all normal projection points of the initial array on the plane.", py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_GeomPlate_BuildAveragePlane.def_static("HalfSpace_", (Standard_Boolean (*)(const TColgp_SequenceOfVec &, TColgp_SequenceOfVec &, GeomPlate_SequenceOfAij &, const Standard_Real, const Standard_Real)) &GeomPlate_BuildAveragePlane::HalfSpace, "None", py::arg("NewNormals"), py::arg("Normals"), py::arg("Bset"), py::arg("LinTol"), py::arg("AngTol"));

// Enums

}