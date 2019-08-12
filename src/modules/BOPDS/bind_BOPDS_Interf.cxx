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
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Handle.hxx>
#include <BOPDS_Interf.hxx>

void bind_BOPDS_Interf(py::module &mod){

py::class_<BOPDS_Interf, std::unique_ptr<BOPDS_Interf, py::nodelete>> cls_BOPDS_Interf(mod, "BOPDS_Interf", "The class BOPDS_Interf is is to store the information about the interference between two shapes. The class BOPDS_Interf is root class");

// Constructors

// Fields

// Methods
cls_BOPDS_Interf.def("SetIndices", (void (BOPDS_Interf::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_Interf::SetIndices, "Sets the indices of interferred shapes", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_Interf.def("Indices", [](BOPDS_Interf &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Returns the indices of interferred shapes", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_Interf.def("SetIndex1", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex1, "Sets the index of the first interferred shape", py::arg("theIndex"));
cls_BOPDS_Interf.def("SetIndex2", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndex2, "Sets the index of the second interferred shape", py::arg("theIndex"));
cls_BOPDS_Interf.def("Index1", (Standard_Integer (BOPDS_Interf::*)() const) &BOPDS_Interf::Index1, "Returns the index of the first interferred shape");
cls_BOPDS_Interf.def("Index2", (Standard_Integer (BOPDS_Interf::*)() const) &BOPDS_Interf::Index2, "Returns the index of the second interferred shape");
cls_BOPDS_Interf.def("OppositeIndex", (Standard_Integer (BOPDS_Interf::*)(const Standard_Integer) const) &BOPDS_Interf::OppositeIndex, "Returns the index of that are opposite to the given index", py::arg("theI"));
cls_BOPDS_Interf.def("Contains", (Standard_Boolean (BOPDS_Interf::*)(const Standard_Integer) const) &BOPDS_Interf::Contains, "Returns true if the interference contains given index", py::arg("theIndex"));
cls_BOPDS_Interf.def("SetIndexNew", (void (BOPDS_Interf::*)(const Standard_Integer)) &BOPDS_Interf::SetIndexNew, "Sets the index of new shape", py::arg("theIndex"));
cls_BOPDS_Interf.def("IndexNew", (Standard_Integer (BOPDS_Interf::*)() const) &BOPDS_Interf::IndexNew, "Returns the index of new shape");
cls_BOPDS_Interf.def("HasIndexNew", [](BOPDS_Interf &self, Standard_Integer & theIndex){ Standard_Boolean rv = self.HasIndexNew(theIndex); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theIndex); }, "Returns true if the interference has index of new shape that is equal to the given index", py::arg("theIndex"));
cls_BOPDS_Interf.def("HasIndexNew", (Standard_Boolean (BOPDS_Interf::*)() const) &BOPDS_Interf::HasIndexNew, "Returns true if the interference has index of new shape the index");

// Enums

}