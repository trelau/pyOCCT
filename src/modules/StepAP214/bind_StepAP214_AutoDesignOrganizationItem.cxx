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
#include <StepAP214_AutoDesignGeneralOrgItem.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_Document.hxx>
#include <StepBasic_PhysicallyModeledProductDefinition.hxx>
#include <StepAP214_AutoDesignOrganizationItem.hxx>

void bind_StepAP214_AutoDesignOrganizationItem(py::module &mod){

py::class_<StepAP214_AutoDesignOrganizationItem, std::unique_ptr<StepAP214_AutoDesignOrganizationItem, Deleter<StepAP214_AutoDesignOrganizationItem>>, StepAP214_AutoDesignGeneralOrgItem> cls_StepAP214_AutoDesignOrganizationItem(mod, "StepAP214_AutoDesignOrganizationItem", "None");

// Constructors
cls_StepAP214_AutoDesignOrganizationItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignOrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignOrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignOrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignOrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignOrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignOrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignOrganizationItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignOrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignOrganizationItem::CaseNum, "None", py::arg("ent"));
cls_StepAP214_AutoDesignOrganizationItem.def("Document", (opencascade::handle<StepBasic_Document> (StepAP214_AutoDesignOrganizationItem::*)() const) &StepAP214_AutoDesignOrganizationItem::Document, "None");
cls_StepAP214_AutoDesignOrganizationItem.def("PhysicallyModeledProductDefinition", (opencascade::handle<StepBasic_PhysicallyModeledProductDefinition> (StepAP214_AutoDesignOrganizationItem::*)() const) &StepAP214_AutoDesignOrganizationItem::PhysicallyModeledProductDefinition, "None");

// Enums

}