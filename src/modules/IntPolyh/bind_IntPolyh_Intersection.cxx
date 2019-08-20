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
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntPolyh_PMaillageAffinage.hxx>
#include <IntPolyh_ArrayOfPointNormal.hxx>
#include <IntPolyh_ListOfCouples.hxx>
#include <IntPolyh_ArrayOfSectionLines.hxx>
#include <IntPolyh_ArrayOfTangentZones.hxx>
#include <IntPolyh_Intersection.hxx>

void bind_IntPolyh_Intersection(py::module &mod){

py::class_<IntPolyh_Intersection, std::unique_ptr<IntPolyh_Intersection>> cls_IntPolyh_Intersection(mod, "IntPolyh_Intersection", "API algorithm for intersection of two surfaces by intersection of their triangulations.");

// Constructors
cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theS1"), py::arg("theS2"));
cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("theS1"), py::arg("theNbSU1"), py::arg("theNbSV1"), py::arg("theS2"), py::arg("theNbSU2"), py::arg("theNbSV2"));
cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("theS1"), py::arg("theUPars1"), py::arg("theVPars1"), py::arg("theS2"), py::arg("theUPars2"), py::arg("theVPars2"));

// Fields

// Methods
// cls_IntPolyh_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_Intersection.def_static("operator delete_", (void (*)(void *)) &IntPolyh_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_Intersection.def("IsDone", (Standard_Boolean (IntPolyh_Intersection::*)() const) &IntPolyh_Intersection::IsDone, "Returns state of the operation");
cls_IntPolyh_Intersection.def("NbSectionLines", (Standard_Integer (IntPolyh_Intersection::*)() const) &IntPolyh_Intersection::NbSectionLines, "Returns the number of section lines");
cls_IntPolyh_Intersection.def("NbPointsInLine", (Standard_Integer (IntPolyh_Intersection::*)(const Standard_Integer) const) &IntPolyh_Intersection::NbPointsInLine, "Returns the number of points in the given line", py::arg("IndexLine"));
cls_IntPolyh_Intersection.def("NbTangentZones", (Standard_Integer (IntPolyh_Intersection::*)() const) &IntPolyh_Intersection::NbTangentZones, "None");
cls_IntPolyh_Intersection.def("NbPointsInTangentZone", (Standard_Integer (IntPolyh_Intersection::*)(const Standard_Integer) const) &IntPolyh_Intersection::NbPointsInTangentZone, "Returns number of points in tangent zone", py::arg(""));
cls_IntPolyh_Intersection.def("GetLinePoint", [](IntPolyh_Intersection &self, const Standard_Integer IndexLine, const Standard_Integer IndexPoint, Standard_Real & x, Standard_Real & y, Standard_Real & z, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, Standard_Real & incidence){ self.GetLinePoint(IndexLine, IndexPoint, x, y, z, u1, v1, u2, v2, incidence); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(x, y, z, u1, v1, u2, v2, incidence); }, "Gets the parameters of the point in section line", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("incidence"));
cls_IntPolyh_Intersection.def("GetTangentZonePoint", [](IntPolyh_Intersection &self, const Standard_Integer IndexLine, const Standard_Integer IndexPoint, Standard_Real & x, Standard_Real & y, Standard_Real & z, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2){ self.GetTangentZonePoint(IndexLine, IndexPoint, x, y, z, u1, v1, u2, v2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(x, y, z, u1, v1, u2, v2); }, "Gets the parameters of the point in tangent zone", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"));

// Enums

}