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
#ifndef __NCollection_CellFilter__
#define __NCollection_CellFilter__

#include <pyOCCT_Common.hxx>
#include <NCollection_CellFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_LocalArray.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Map.hxx>

template <typename Inspector>
void bind_NCollection_CellFilter(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_CellFilter<Inspector>, std::unique_ptr<NCollection_CellFilter<Inspector>, Deleter<NCollection_CellFilter<Inspector>>>> cls_NCollection_CellFilter(mod, name.c_str(), "A data structure for sorting geometric objects (called targets) in n-dimensional space into cells, with associated algorithm for fast checking of coincidence (overlapping, intersection, etc.) with other objects (called here bullets).", local);

// Constructors
cls_NCollection_CellFilter.def(py::init<const Standard_Integer>(), py::arg("theDim"));
cls_NCollection_CellFilter.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("theDim"), py::arg("theCellSize"));
cls_NCollection_CellFilter.def(py::init<const Standard_Integer, const Standard_Real, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theDim"), py::arg("theCellSize"), py::arg("theAlloc"));
cls_NCollection_CellFilter.def(py::init<>());
cls_NCollection_CellFilter.def(py::init<const Standard_Real>(), py::arg("theCellSize"));
cls_NCollection_CellFilter.def(py::init<const Standard_Real, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theCellSize"), py::arg("theAlloc"));

// Fields

// Methods
cls_NCollection_CellFilter.def("Reset", [](NCollection_CellFilter<Inspector> &self, Standard_Real a0) -> void { return self.Reset(a0); });
cls_NCollection_CellFilter.def("Reset", (void (NCollection_CellFilter<Inspector>::*)(Standard_Real, const opencascade::handle<NCollection_IncAllocator> &)) &NCollection_CellFilter<Inspector>::Reset, "Clear the data structures, set new cell size and allocator", py::arg("theCellSize"), py::arg("theAlloc"));
cls_NCollection_CellFilter.def("Reset", [](NCollection_CellFilter<Inspector> &self, NCollection_Array1<Standard_Real> & a0) -> void { return self.Reset(a0); });
cls_NCollection_CellFilter.def("Reset", (void (NCollection_CellFilter<Inspector>::*)(NCollection_Array1<Standard_Real> &, const opencascade::handle<NCollection_IncAllocator> &)) &NCollection_CellFilter<Inspector>::Reset, "Clear the data structures and set new cell sizes and allocator", py::arg("theCellSize"), py::arg("theAlloc"));
cls_NCollection_CellFilter.def("Add", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Target &, const NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Add, "Adds a target object for further search at a point (into only one cell)", py::arg("theTarget"), py::arg("thePnt"));
cls_NCollection_CellFilter.def("Add", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Target &, const NCollection_CellFilter<Inspector>::Point &, const NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Add, "Adds a target object for further search in the range of cells defined by two points (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point)", py::arg("theTarget"), py::arg("thePntMin"), py::arg("thePntMax"));
cls_NCollection_CellFilter.def("Remove", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Target &, const NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Remove, "Find a target object at a point and remove it from the structures. For usage of this method 'operator ==' should be defined for Target.", py::arg("theTarget"), py::arg("thePnt"));
cls_NCollection_CellFilter.def("Remove", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Target &, const NCollection_CellFilter<Inspector>::Point &, const NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Remove, "Find a target object in the range of cells defined by two points and remove it from the structures (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point). For usage of this method 'operator ==' should be defined for Target.", py::arg("theTarget"), py::arg("thePntMin"), py::arg("thePntMax"));
cls_NCollection_CellFilter.def("Inspect", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Point &, Inspector &)) &NCollection_CellFilter<Inspector>::Inspect, "Inspect all targets in the cell corresponding to the given point", py::arg("thePnt"), py::arg("theInspector"));
cls_NCollection_CellFilter.def("Inspect", (void (NCollection_CellFilter<Inspector>::*)(const NCollection_CellFilter<Inspector>::Point &, const NCollection_CellFilter<Inspector>::Point &, Inspector &)) &NCollection_CellFilter<Inspector>::Inspect, "Inspect all targets in the cells range limited by two given points (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point)", py::arg("thePntMin"), py::arg("thePntMax"), py::arg("theInspector"));

// Enums

}

#endif