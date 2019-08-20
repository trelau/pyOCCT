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
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Mutex.hxx>
#include <TopTools_MutexForShapeProvider.hxx>
#include <NCollection_DataMap.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>

void bind_TopTools_MutexForShapeProvider(py::module &mod){

py::class_<TopTools_MutexForShapeProvider, std::unique_ptr<TopTools_MutexForShapeProvider>> cls_TopTools_MutexForShapeProvider(mod, "TopTools_MutexForShapeProvider", "Class TopTools_MutexForShapeProvider This class is used to create and store mutexes associated with shapes.");

// Constructors
cls_TopTools_MutexForShapeProvider.def(py::init<>());

// Fields

// Methods
cls_TopTools_MutexForShapeProvider.def("CreateMutexesForSubShapes", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopTools_MutexForShapeProvider::CreateMutexesForSubShapes, "Creates and associates mutexes with each sub-shape of type theType in theShape.", py::arg("theShape"), py::arg("theType"));
cls_TopTools_MutexForShapeProvider.def("CreateMutexForShape", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &)) &TopTools_MutexForShapeProvider::CreateMutexForShape, "Creates and associates mutex with theShape", py::arg("theShape"));
cls_TopTools_MutexForShapeProvider.def("GetMutex", (Standard_Mutex * (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &) const) &TopTools_MutexForShapeProvider::GetMutex, "Returns pointer to mutex associated with theShape. In case when mutex not found returns NULL.", py::arg("theShape"));
cls_TopTools_MutexForShapeProvider.def("RemoveAllMutexes", (void (TopTools_MutexForShapeProvider::*)()) &TopTools_MutexForShapeProvider::RemoveAllMutexes, "Removes all mutexes");

// Enums

}