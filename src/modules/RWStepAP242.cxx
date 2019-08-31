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
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepAP242_DraughtingModelItemAssociation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepAP242_RWDraughtingModelItemAssociation.hxx>
#include <StepAP242_GeometricItemSpecificUsage.hxx>
#include <RWStepAP242_RWGeometricItemSpecificUsage.hxx>
#include <StepAP242_IdAttribute.hxx>
#include <RWStepAP242_RWIdAttribute.hxx>
#include <StepAP242_ItemIdentifiedRepresentationUsage.hxx>
#include <RWStepAP242_RWItemIdentifiedRepresentationUsage.hxx>

PYBIND11_MODULE(RWStepAP242, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepAP242");

// CLASS: RWSTEPAP242_RWDRAUGHTINGMODELITEMASSOCIATION
py::class_<RWStepAP242_RWDraughtingModelItemAssociation> cls_RWStepAP242_RWDraughtingModelItemAssociation(mod, "RWStepAP242_RWDraughtingModelItemAssociation", "Read & Write Module for DraughtingModelItemAssociation");

// Constructors
cls_RWStepAP242_RWDraughtingModelItemAssociation.def(py::init<>());

// Methods
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator new_", (void * (*)(size_t)) &RWStepAP242_RWDraughtingModelItemAssociation::operator new, "None", py::arg("theSize"));
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator delete_", (void (*)(void *)) &RWStepAP242_RWDraughtingModelItemAssociation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP242_RWDraughtingModelItemAssociation::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP242_RWDraughtingModelItemAssociation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP242_RWDraughtingModelItemAssociation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP242_RWDraughtingModelItemAssociation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP242_RWDraughtingModelItemAssociation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP242_RWDraughtingModelItemAssociation.def("ReadStep", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &) const) &RWStepAP242_RWDraughtingModelItemAssociation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP242_RWDraughtingModelItemAssociation.def("WriteStep", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &) const) &RWStepAP242_RWDraughtingModelItemAssociation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP242_RWDraughtingModelItemAssociation.def("Share", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &, Interface_EntityIterator &) const) &RWStepAP242_RWDraughtingModelItemAssociation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP242_RWGEOMETRICITEMSPECIFICUSAGE
py::class_<RWStepAP242_RWGeometricItemSpecificUsage> cls_RWStepAP242_RWGeometricItemSpecificUsage(mod, "RWStepAP242_RWGeometricItemSpecificUsage", "Read & Write Module for GeometricItemSpecificUsage");

// Constructors
cls_RWStepAP242_RWGeometricItemSpecificUsage.def(py::init<>());

// Methods
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepAP242_RWGeometricItemSpecificUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator delete_", (void (*)(void *)) &RWStepAP242_RWGeometricItemSpecificUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP242_RWGeometricItemSpecificUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP242_RWGeometricItemSpecificUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP242_RWGeometricItemSpecificUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP242_RWGeometricItemSpecificUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP242_RWGeometricItemSpecificUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP242_RWGeometricItemSpecificUsage.def("ReadStep", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &) const) &RWStepAP242_RWGeometricItemSpecificUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP242_RWGeometricItemSpecificUsage.def("WriteStep", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &) const) &RWStepAP242_RWGeometricItemSpecificUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP242_RWGeometricItemSpecificUsage.def("Share", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &, Interface_EntityIterator &) const) &RWStepAP242_RWGeometricItemSpecificUsage::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP242_RWIDATTRIBUTE
py::class_<RWStepAP242_RWIdAttribute> cls_RWStepAP242_RWIdAttribute(mod, "RWStepAP242_RWIdAttribute", "Read & Write Module for IdAttribute");

// Constructors
cls_RWStepAP242_RWIdAttribute.def(py::init<>());

// Methods
// cls_RWStepAP242_RWIdAttribute.def_static("operator new_", (void * (*)(size_t)) &RWStepAP242_RWIdAttribute::operator new, "None", py::arg("theSize"));
// cls_RWStepAP242_RWIdAttribute.def_static("operator delete_", (void (*)(void *)) &RWStepAP242_RWIdAttribute::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP242_RWIdAttribute.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP242_RWIdAttribute::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP242_RWIdAttribute.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP242_RWIdAttribute::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP242_RWIdAttribute.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP242_RWIdAttribute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP242_RWIdAttribute.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP242_RWIdAttribute::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP242_RWIdAttribute.def("ReadStep", (void (RWStepAP242_RWIdAttribute::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_IdAttribute> &) const) &RWStepAP242_RWIdAttribute::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP242_RWIdAttribute.def("WriteStep", (void (RWStepAP242_RWIdAttribute::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_IdAttribute> &) const) &RWStepAP242_RWIdAttribute::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP242_RWIdAttribute.def("Share", (void (RWStepAP242_RWIdAttribute::*)(const opencascade::handle<StepAP242_IdAttribute> &, Interface_EntityIterator &) const) &RWStepAP242_RWIdAttribute::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP242_RWITEMIDENTIFIEDREPRESENTATIONUSAGE
py::class_<RWStepAP242_RWItemIdentifiedRepresentationUsage> cls_RWStepAP242_RWItemIdentifiedRepresentationUsage(mod, "RWStepAP242_RWItemIdentifiedRepresentationUsage", "Read & Write Module for ItemIdentifiedRepresentationUsage");

// Constructors
cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def(py::init<>());

// Methods
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator delete_", (void (*)(void *)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP242_RWItemIdentifiedRepresentationUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("ReadStep", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &) const) &RWStepAP242_RWItemIdentifiedRepresentationUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("WriteStep", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &) const) &RWStepAP242_RWItemIdentifiedRepresentationUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("Share", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &, Interface_EntityIterator &) const) &RWStepAP242_RWItemIdentifiedRepresentationUsage::Share, "None", py::arg("ent"), py::arg("iter"));


}
