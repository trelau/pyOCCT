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
#include <Standard_Handle.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard.hxx>
#include <SelectMgr_SortCriterion.hxx>
#include <Precision.hxx>

void bind_SelectMgr_SortCriterion(py::module &mod){

py::class_<SelectMgr_SortCriterion, std::unique_ptr<SelectMgr_SortCriterion>> cls_SelectMgr_SortCriterion(mod, "SelectMgr_SortCriterion", "This class provides data and criterion for sorting candidate entities in the process of interactive selection by mouse click");

// Constructors
cls_SelectMgr_SortCriterion.def(py::init<>());

// Fields
cls_SelectMgr_SortCriterion.def_readwrite("Entity", &SelectMgr_SortCriterion::Entity, "detected entity");
cls_SelectMgr_SortCriterion.def_readwrite("Point", &SelectMgr_SortCriterion::Point, "3D point");
cls_SelectMgr_SortCriterion.def_readwrite("Depth", &SelectMgr_SortCriterion::Depth, "distance from the view plane to the entity");
cls_SelectMgr_SortCriterion.def_readwrite("MinDist", &SelectMgr_SortCriterion::MinDist, "distance from the clicked point to the entity on the view plane");
cls_SelectMgr_SortCriterion.def_readwrite("Tolerance", &SelectMgr_SortCriterion::Tolerance, "tolerance used for selecting candidates");
cls_SelectMgr_SortCriterion.def_readwrite("Priority", &SelectMgr_SortCriterion::Priority, "selection priority");
cls_SelectMgr_SortCriterion.def_readwrite("ZLayerPosition", &SelectMgr_SortCriterion::ZLayerPosition, "ZLayer rendering order index, stronger than a depth");
cls_SelectMgr_SortCriterion.def_readwrite("NbOwnerMatches", &SelectMgr_SortCriterion::NbOwnerMatches, "overall number of entities collected for the same owner");
cls_SelectMgr_SortCriterion.def_readwrite("ToPreferClosest", &SelectMgr_SortCriterion::ToPreferClosest, "whether closest object is preferred even if has less priority");

// Methods
// cls_SelectMgr_SortCriterion.def_static("operator new_", (void * (*)(size_t)) &SelectMgr_SortCriterion::operator new, "None", py::arg("theSize"));
// cls_SelectMgr_SortCriterion.def_static("operator delete_", (void (*)(void *)) &SelectMgr_SortCriterion::operator delete, "None", py::arg("theAddress"));
// cls_SelectMgr_SortCriterion.def_static("operator new[]_", (void * (*)(size_t)) &SelectMgr_SortCriterion::operator new[], "None", py::arg("theSize"));
// cls_SelectMgr_SortCriterion.def_static("operator delete[]_", (void (*)(void *)) &SelectMgr_SortCriterion::operator delete[], "None", py::arg("theAddress"));
// cls_SelectMgr_SortCriterion.def_static("operator new_", (void * (*)(size_t, void *)) &SelectMgr_SortCriterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_SelectMgr_SortCriterion.def_static("operator delete_", (void (*)(void *, void *)) &SelectMgr_SortCriterion::operator delete, "None", py::arg(""), py::arg(""));
cls_SelectMgr_SortCriterion.def("__gt__", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const) &SelectMgr_SortCriterion::operator>, py::is_operator(), "Comparison operator.", py::arg("theOther"));
cls_SelectMgr_SortCriterion.def("__lt__", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const) &SelectMgr_SortCriterion::operator<, py::is_operator(), "Comparison operator.", py::arg("theOther"));
cls_SelectMgr_SortCriterion.def("IsGreater", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const) &SelectMgr_SortCriterion::IsGreater, "Compare with another item.", py::arg("theOther"));
cls_SelectMgr_SortCriterion.def("IsLower", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const) &SelectMgr_SortCriterion::IsLower, "Compare with another item.", py::arg("theOther"));

// Enums

}