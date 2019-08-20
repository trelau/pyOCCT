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
#include <TopOpeBRepDS_GeometryData.hxx>
#include <Standard.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepDS_PointData.hxx>

void bind_TopOpeBRepDS_PointData(py::module &mod){

py::class_<TopOpeBRepDS_PointData, std::unique_ptr<TopOpeBRepDS_PointData>, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_PointData(mod, "TopOpeBRepDS_PointData", "None");

// Constructors
cls_TopOpeBRepDS_PointData.def(py::init<>());
cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &>(), py::arg("P"));
cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &, const Standard_Integer, const Standard_Integer>(), py::arg("P"), py::arg("I1"), py::arg("I2"));

// Fields

// Methods
// cls_TopOpeBRepDS_PointData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointData::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointData.def("SetShapes", (void (TopOpeBRepDS_PointData::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_PointData::SetShapes, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_PointData.def("GetShapes", [](TopOpeBRepDS_PointData &self, Standard_Integer & I1, Standard_Integer & I2){ self.GetShapes(I1, I2); return std::tuple<Standard_Integer &, Standard_Integer &>(I1, I2); }, "None", py::arg("I1"), py::arg("I2"));

// Enums

}