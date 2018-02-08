/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

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

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepAP242");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP242_RWDraughtingModelItemAssociation.hxx
	py::class_<RWStepAP242_RWDraughtingModelItemAssociation, std::unique_ptr<RWStepAP242_RWDraughtingModelItemAssociation, Deleter<RWStepAP242_RWDraughtingModelItemAssociation>>> cls_RWStepAP242_RWDraughtingModelItemAssociation(mod, "RWStepAP242_RWDraughtingModelItemAssociation", "Read & Write Module for DraughtingModelItemAssociation");
	cls_RWStepAP242_RWDraughtingModelItemAssociation.def(py::init<>());
	cls_RWStepAP242_RWDraughtingModelItemAssociation.def("ReadStep", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &) const ) &RWStepAP242_RWDraughtingModelItemAssociation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP242_RWDraughtingModelItemAssociation.def("WriteStep", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &) const ) &RWStepAP242_RWDraughtingModelItemAssociation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP242_RWDraughtingModelItemAssociation.def("Share", (void (RWStepAP242_RWDraughtingModelItemAssociation::*)(const opencascade::handle<StepAP242_DraughtingModelItemAssociation> &, Interface_EntityIterator &) const ) &RWStepAP242_RWDraughtingModelItemAssociation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP242_RWGeometricItemSpecificUsage.hxx
	py::class_<RWStepAP242_RWGeometricItemSpecificUsage, std::unique_ptr<RWStepAP242_RWGeometricItemSpecificUsage, Deleter<RWStepAP242_RWGeometricItemSpecificUsage>>> cls_RWStepAP242_RWGeometricItemSpecificUsage(mod, "RWStepAP242_RWGeometricItemSpecificUsage", "Read & Write Module for GeometricItemSpecificUsage");
	cls_RWStepAP242_RWGeometricItemSpecificUsage.def(py::init<>());
	cls_RWStepAP242_RWGeometricItemSpecificUsage.def("ReadStep", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &) const ) &RWStepAP242_RWGeometricItemSpecificUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP242_RWGeometricItemSpecificUsage.def("WriteStep", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &) const ) &RWStepAP242_RWGeometricItemSpecificUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP242_RWGeometricItemSpecificUsage.def("Share", (void (RWStepAP242_RWGeometricItemSpecificUsage::*)(const opencascade::handle<StepAP242_GeometricItemSpecificUsage> &, Interface_EntityIterator &) const ) &RWStepAP242_RWGeometricItemSpecificUsage::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP242_RWIdAttribute.hxx
	py::class_<RWStepAP242_RWIdAttribute, std::unique_ptr<RWStepAP242_RWIdAttribute, Deleter<RWStepAP242_RWIdAttribute>>> cls_RWStepAP242_RWIdAttribute(mod, "RWStepAP242_RWIdAttribute", "Read & Write Module for IdAttribute");
	cls_RWStepAP242_RWIdAttribute.def(py::init<>());
	cls_RWStepAP242_RWIdAttribute.def("ReadStep", (void (RWStepAP242_RWIdAttribute::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_IdAttribute> &) const ) &RWStepAP242_RWIdAttribute::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP242_RWIdAttribute.def("WriteStep", (void (RWStepAP242_RWIdAttribute::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_IdAttribute> &) const ) &RWStepAP242_RWIdAttribute::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP242_RWIdAttribute.def("Share", (void (RWStepAP242_RWIdAttribute::*)(const opencascade::handle<StepAP242_IdAttribute> &, Interface_EntityIterator &) const ) &RWStepAP242_RWIdAttribute::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP242_RWItemIdentifiedRepresentationUsage.hxx
	py::class_<RWStepAP242_RWItemIdentifiedRepresentationUsage, std::unique_ptr<RWStepAP242_RWItemIdentifiedRepresentationUsage, Deleter<RWStepAP242_RWItemIdentifiedRepresentationUsage>>> cls_RWStepAP242_RWItemIdentifiedRepresentationUsage(mod, "RWStepAP242_RWItemIdentifiedRepresentationUsage", "Read & Write Module for ItemIdentifiedRepresentationUsage");
	cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def(py::init<>());
	cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("ReadStep", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &) const ) &RWStepAP242_RWItemIdentifiedRepresentationUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("WriteStep", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(StepData_StepWriter &, const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &) const ) &RWStepAP242_RWItemIdentifiedRepresentationUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP242_RWItemIdentifiedRepresentationUsage.def("Share", (void (RWStepAP242_RWItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage> &, Interface_EntityIterator &) const ) &RWStepAP242_RWItemIdentifiedRepresentationUsage::Share, "None", py::arg("ent"), py::arg("iter"));


}
