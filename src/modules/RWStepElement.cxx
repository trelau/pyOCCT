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
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepElement_RWAnalysisItemWithinRepresentation.hxx>
#include <StepElement_Curve3dElementDescriptor.hxx>
#include <RWStepElement_RWCurve3dElementDescriptor.hxx>
#include <StepElement_CurveElementEndReleasePacket.hxx>
#include <RWStepElement_RWCurveElementEndReleasePacket.hxx>
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <RWStepElement_RWCurveElementSectionDefinition.hxx>
#include <StepElement_CurveElementSectionDerivedDefinitions.hxx>
#include <RWStepElement_RWCurveElementSectionDerivedDefinitions.hxx>
#include <StepElement_ElementDescriptor.hxx>
#include <RWStepElement_RWElementDescriptor.hxx>
#include <StepElement_ElementMaterial.hxx>
#include <RWStepElement_RWElementMaterial.hxx>
#include <StepElement_Surface3dElementDescriptor.hxx>
#include <RWStepElement_RWSurface3dElementDescriptor.hxx>
#include <StepElement_SurfaceElementProperty.hxx>
#include <RWStepElement_RWSurfaceElementProperty.hxx>
#include <StepElement_SurfaceSection.hxx>
#include <RWStepElement_RWSurfaceSection.hxx>
#include <StepElement_SurfaceSectionField.hxx>
#include <RWStepElement_RWSurfaceSectionField.hxx>
#include <StepElement_SurfaceSectionFieldConstant.hxx>
#include <RWStepElement_RWSurfaceSectionFieldConstant.hxx>
#include <StepElement_SurfaceSectionFieldVarying.hxx>
#include <RWStepElement_RWSurfaceSectionFieldVarying.hxx>
#include <StepElement_UniformSurfaceSection.hxx>
#include <RWStepElement_RWUniformSurfaceSection.hxx>
#include <StepElement_Volume3dElementDescriptor.hxx>
#include <RWStepElement_RWVolume3dElementDescriptor.hxx>

PYBIND11_MODULE(RWStepElement, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepElement");

// CLASS: RWSTEPELEMENT_RWANALYSISITEMWITHINREPRESENTATION
py::class_<RWStepElement_RWAnalysisItemWithinRepresentation> cls_RWStepElement_RWAnalysisItemWithinRepresentation(mod, "RWStepElement_RWAnalysisItemWithinRepresentation", "Read & Write tool for AnalysisItemWithinRepresentation");

// Constructors
cls_RWStepElement_RWAnalysisItemWithinRepresentation.def(py::init<>());

// Methods
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWAnalysisItemWithinRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWAnalysisItemWithinRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWAnalysisItemWithinRepresentation.def("ReadStep", (void (RWStepElement_RWAnalysisItemWithinRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &) const) &RWStepElement_RWAnalysisItemWithinRepresentation::ReadStep, "Reads AnalysisItemWithinRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWAnalysisItemWithinRepresentation.def("WriteStep", (void (RWStepElement_RWAnalysisItemWithinRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &) const) &RWStepElement_RWAnalysisItemWithinRepresentation::WriteStep, "Writes AnalysisItemWithinRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWAnalysisItemWithinRepresentation.def("Share", (void (RWStepElement_RWAnalysisItemWithinRepresentation::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &, Interface_EntityIterator &) const) &RWStepElement_RWAnalysisItemWithinRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWCURVE3DELEMENTDESCRIPTOR
py::class_<RWStepElement_RWCurve3dElementDescriptor> cls_RWStepElement_RWCurve3dElementDescriptor(mod, "RWStepElement_RWCurve3dElementDescriptor", "Read & Write tool for Curve3dElementDescriptor");

// Constructors
cls_RWStepElement_RWCurve3dElementDescriptor.def(py::init<>());

// Methods
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWCurve3dElementDescriptor::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWCurve3dElementDescriptor::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWCurve3dElementDescriptor::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWCurve3dElementDescriptor::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWCurve3dElementDescriptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWCurve3dElementDescriptor.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWCurve3dElementDescriptor::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWCurve3dElementDescriptor.def("ReadStep", (void (RWStepElement_RWCurve3dElementDescriptor::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_Curve3dElementDescriptor> &) const) &RWStepElement_RWCurve3dElementDescriptor::ReadStep, "Reads Curve3dElementDescriptor", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWCurve3dElementDescriptor.def("WriteStep", (void (RWStepElement_RWCurve3dElementDescriptor::*)(StepData_StepWriter &, const opencascade::handle<StepElement_Curve3dElementDescriptor> &) const) &RWStepElement_RWCurve3dElementDescriptor::WriteStep, "Writes Curve3dElementDescriptor", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWCurve3dElementDescriptor.def("Share", (void (RWStepElement_RWCurve3dElementDescriptor::*)(const opencascade::handle<StepElement_Curve3dElementDescriptor> &, Interface_EntityIterator &) const) &RWStepElement_RWCurve3dElementDescriptor::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWCURVEELEMENTENDRELEASEPACKET
py::class_<RWStepElement_RWCurveElementEndReleasePacket> cls_RWStepElement_RWCurveElementEndReleasePacket(mod, "RWStepElement_RWCurveElementEndReleasePacket", "Read & Write tool for CurveElementEndReleasePacket");

// Constructors
cls_RWStepElement_RWCurveElementEndReleasePacket.def(py::init<>());

// Methods
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWCurveElementEndReleasePacket::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWCurveElementEndReleasePacket::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("ReadStep", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_CurveElementEndReleasePacket> &) const) &RWStepElement_RWCurveElementEndReleasePacket::ReadStep, "Reads CurveElementEndReleasePacket", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("WriteStep", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(StepData_StepWriter &, const opencascade::handle<StepElement_CurveElementEndReleasePacket> &) const) &RWStepElement_RWCurveElementEndReleasePacket::WriteStep, "Writes CurveElementEndReleasePacket", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("Share", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(const opencascade::handle<StepElement_CurveElementEndReleasePacket> &, Interface_EntityIterator &) const) &RWStepElement_RWCurveElementEndReleasePacket::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWCURVEELEMENTSECTIONDEFINITION
py::class_<RWStepElement_RWCurveElementSectionDefinition> cls_RWStepElement_RWCurveElementSectionDefinition(mod, "RWStepElement_RWCurveElementSectionDefinition", "Read & Write tool for CurveElementSectionDefinition");

// Constructors
cls_RWStepElement_RWCurveElementSectionDefinition.def(py::init<>());

// Methods
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWCurveElementSectionDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWCurveElementSectionDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWCurveElementSectionDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWCurveElementSectionDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWCurveElementSectionDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWCurveElementSectionDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWCurveElementSectionDefinition.def("ReadStep", (void (RWStepElement_RWCurveElementSectionDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_CurveElementSectionDefinition> &) const) &RWStepElement_RWCurveElementSectionDefinition::ReadStep, "Reads CurveElementSectionDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWCurveElementSectionDefinition.def("WriteStep", (void (RWStepElement_RWCurveElementSectionDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepElement_CurveElementSectionDefinition> &) const) &RWStepElement_RWCurveElementSectionDefinition::WriteStep, "Writes CurveElementSectionDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWCurveElementSectionDefinition.def("Share", (void (RWStepElement_RWCurveElementSectionDefinition::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &, Interface_EntityIterator &) const) &RWStepElement_RWCurveElementSectionDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWCURVEELEMENTSECTIONDERIVEDDEFINITIONS
py::class_<RWStepElement_RWCurveElementSectionDerivedDefinitions> cls_RWStepElement_RWCurveElementSectionDerivedDefinitions(mod, "RWStepElement_RWCurveElementSectionDerivedDefinitions", "Read & Write tool for CurveElementSectionDerivedDefinitions");

// Constructors
cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def(py::init<>());

// Methods
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWCurveElementSectionDerivedDefinitions::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def("ReadStep", (void (RWStepElement_RWCurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_CurveElementSectionDerivedDefinitions> &) const) &RWStepElement_RWCurveElementSectionDerivedDefinitions::ReadStep, "Reads CurveElementSectionDerivedDefinitions", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def("WriteStep", (void (RWStepElement_RWCurveElementSectionDerivedDefinitions::*)(StepData_StepWriter &, const opencascade::handle<StepElement_CurveElementSectionDerivedDefinitions> &) const) &RWStepElement_RWCurveElementSectionDerivedDefinitions::WriteStep, "Writes CurveElementSectionDerivedDefinitions", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWCurveElementSectionDerivedDefinitions.def("Share", (void (RWStepElement_RWCurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_CurveElementSectionDerivedDefinitions> &, Interface_EntityIterator &) const) &RWStepElement_RWCurveElementSectionDerivedDefinitions::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWELEMENTDESCRIPTOR
py::class_<RWStepElement_RWElementDescriptor> cls_RWStepElement_RWElementDescriptor(mod, "RWStepElement_RWElementDescriptor", "Read & Write tool for ElementDescriptor");

// Constructors
cls_RWStepElement_RWElementDescriptor.def(py::init<>());

// Methods
// cls_RWStepElement_RWElementDescriptor.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWElementDescriptor::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWElementDescriptor.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWElementDescriptor::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementDescriptor.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWElementDescriptor::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWElementDescriptor.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWElementDescriptor::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementDescriptor.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWElementDescriptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWElementDescriptor.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWElementDescriptor::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWElementDescriptor.def("ReadStep", (void (RWStepElement_RWElementDescriptor::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_ElementDescriptor> &) const) &RWStepElement_RWElementDescriptor::ReadStep, "Reads ElementDescriptor", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWElementDescriptor.def("WriteStep", (void (RWStepElement_RWElementDescriptor::*)(StepData_StepWriter &, const opencascade::handle<StepElement_ElementDescriptor> &) const) &RWStepElement_RWElementDescriptor::WriteStep, "Writes ElementDescriptor", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWElementDescriptor.def("Share", (void (RWStepElement_RWElementDescriptor::*)(const opencascade::handle<StepElement_ElementDescriptor> &, Interface_EntityIterator &) const) &RWStepElement_RWElementDescriptor::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWELEMENTMATERIAL
py::class_<RWStepElement_RWElementMaterial> cls_RWStepElement_RWElementMaterial(mod, "RWStepElement_RWElementMaterial", "Read & Write tool for ElementMaterial");

// Constructors
cls_RWStepElement_RWElementMaterial.def(py::init<>());

// Methods
// cls_RWStepElement_RWElementMaterial.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWElementMaterial::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWElementMaterial::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWElementMaterial::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWElementMaterial::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWElementMaterial::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWElementMaterial::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWElementMaterial.def("ReadStep", (void (RWStepElement_RWElementMaterial::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_ElementMaterial> &) const) &RWStepElement_RWElementMaterial::ReadStep, "Reads ElementMaterial", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWElementMaterial.def("WriteStep", (void (RWStepElement_RWElementMaterial::*)(StepData_StepWriter &, const opencascade::handle<StepElement_ElementMaterial> &) const) &RWStepElement_RWElementMaterial::WriteStep, "Writes ElementMaterial", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWElementMaterial.def("Share", (void (RWStepElement_RWElementMaterial::*)(const opencascade::handle<StepElement_ElementMaterial> &, Interface_EntityIterator &) const) &RWStepElement_RWElementMaterial::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACE3DELEMENTDESCRIPTOR
py::class_<RWStepElement_RWSurface3dElementDescriptor> cls_RWStepElement_RWSurface3dElementDescriptor(mod, "RWStepElement_RWSurface3dElementDescriptor", "Read & Write tool for Surface3dElementDescriptor");

// Constructors
cls_RWStepElement_RWSurface3dElementDescriptor.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurface3dElementDescriptor::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurface3dElementDescriptor::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurface3dElementDescriptor::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurface3dElementDescriptor::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurface3dElementDescriptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurface3dElementDescriptor.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurface3dElementDescriptor::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurface3dElementDescriptor.def("ReadStep", (void (RWStepElement_RWSurface3dElementDescriptor::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_Surface3dElementDescriptor> &) const) &RWStepElement_RWSurface3dElementDescriptor::ReadStep, "Reads Surface3dElementDescriptor", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurface3dElementDescriptor.def("WriteStep", (void (RWStepElement_RWSurface3dElementDescriptor::*)(StepData_StepWriter &, const opencascade::handle<StepElement_Surface3dElementDescriptor> &) const) &RWStepElement_RWSurface3dElementDescriptor::WriteStep, "Writes Surface3dElementDescriptor", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurface3dElementDescriptor.def("Share", (void (RWStepElement_RWSurface3dElementDescriptor::*)(const opencascade::handle<StepElement_Surface3dElementDescriptor> &, Interface_EntityIterator &) const) &RWStepElement_RWSurface3dElementDescriptor::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACEELEMENTPROPERTY
py::class_<RWStepElement_RWSurfaceElementProperty> cls_RWStepElement_RWSurfaceElementProperty(mod, "RWStepElement_RWSurfaceElementProperty", "Read & Write tool for SurfaceElementProperty");

// Constructors
cls_RWStepElement_RWSurfaceElementProperty.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceElementProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceElementProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceElementProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceElementProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceElementProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceElementProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceElementProperty.def("ReadStep", (void (RWStepElement_RWSurfaceElementProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceElementProperty> &) const) &RWStepElement_RWSurfaceElementProperty::ReadStep, "Reads SurfaceElementProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceElementProperty.def("WriteStep", (void (RWStepElement_RWSurfaceElementProperty::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceElementProperty> &) const) &RWStepElement_RWSurfaceElementProperty::WriteStep, "Writes SurfaceElementProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceElementProperty.def("Share", (void (RWStepElement_RWSurfaceElementProperty::*)(const opencascade::handle<StepElement_SurfaceElementProperty> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceElementProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACESECTION
py::class_<RWStepElement_RWSurfaceSection> cls_RWStepElement_RWSurfaceSection(mod, "RWStepElement_RWSurfaceSection", "Read & Write tool for SurfaceSection");

// Constructors
cls_RWStepElement_RWSurfaceSection.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurfaceSection.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSection::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceSection::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSection::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceSection::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceSection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceSection.def("ReadStep", (void (RWStepElement_RWSurfaceSection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceSection> &) const) &RWStepElement_RWSurfaceSection::ReadStep, "Reads SurfaceSection", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSection.def("WriteStep", (void (RWStepElement_RWSurfaceSection::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceSection> &) const) &RWStepElement_RWSurfaceSection::WriteStep, "Writes SurfaceSection", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSection.def("Share", (void (RWStepElement_RWSurfaceSection::*)(const opencascade::handle<StepElement_SurfaceSection> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceSection::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACESECTIONFIELD
py::class_<RWStepElement_RWSurfaceSectionField> cls_RWStepElement_RWSurfaceSectionField(mod, "RWStepElement_RWSurfaceSectionField", "Read & Write tool for SurfaceSectionField");

// Constructors
cls_RWStepElement_RWSurfaceSectionField.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionField::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionField::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionField::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionField::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceSectionField::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionField.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceSectionField::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceSectionField.def("ReadStep", (void (RWStepElement_RWSurfaceSectionField::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceSectionField> &) const) &RWStepElement_RWSurfaceSectionField::ReadStep, "Reads SurfaceSectionField", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionField.def("WriteStep", (void (RWStepElement_RWSurfaceSectionField::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceSectionField> &) const) &RWStepElement_RWSurfaceSectionField::WriteStep, "Writes SurfaceSectionField", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionField.def("Share", (void (RWStepElement_RWSurfaceSectionField::*)(const opencascade::handle<StepElement_SurfaceSectionField> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceSectionField::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACESECTIONFIELDCONSTANT
py::class_<RWStepElement_RWSurfaceSectionFieldConstant> cls_RWStepElement_RWSurfaceSectionFieldConstant(mod, "RWStepElement_RWSurfaceSectionFieldConstant", "Read & Write tool for SurfaceSectionFieldConstant");

// Constructors
cls_RWStepElement_RWSurfaceSectionFieldConstant.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionFieldConstant::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionFieldConstant::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionFieldConstant::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionFieldConstant::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceSectionFieldConstant::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldConstant.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceSectionFieldConstant::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceSectionFieldConstant.def("ReadStep", (void (RWStepElement_RWSurfaceSectionFieldConstant::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceSectionFieldConstant> &) const) &RWStepElement_RWSurfaceSectionFieldConstant::ReadStep, "Reads SurfaceSectionFieldConstant", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionFieldConstant.def("WriteStep", (void (RWStepElement_RWSurfaceSectionFieldConstant::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceSectionFieldConstant> &) const) &RWStepElement_RWSurfaceSectionFieldConstant::WriteStep, "Writes SurfaceSectionFieldConstant", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionFieldConstant.def("Share", (void (RWStepElement_RWSurfaceSectionFieldConstant::*)(const opencascade::handle<StepElement_SurfaceSectionFieldConstant> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceSectionFieldConstant::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWSURFACESECTIONFIELDVARYING
py::class_<RWStepElement_RWSurfaceSectionFieldVarying> cls_RWStepElement_RWSurfaceSectionFieldVarying(mod, "RWStepElement_RWSurfaceSectionFieldVarying", "Read & Write tool for SurfaceSectionFieldVarying");

// Constructors
cls_RWStepElement_RWSurfaceSectionFieldVarying.def(py::init<>());

// Methods
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionFieldVarying::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionFieldVarying::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSectionFieldVarying::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceSectionFieldVarying::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceSectionFieldVarying::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSectionFieldVarying.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceSectionFieldVarying::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceSectionFieldVarying.def("ReadStep", (void (RWStepElement_RWSurfaceSectionFieldVarying::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceSectionFieldVarying> &) const) &RWStepElement_RWSurfaceSectionFieldVarying::ReadStep, "Reads SurfaceSectionFieldVarying", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionFieldVarying.def("WriteStep", (void (RWStepElement_RWSurfaceSectionFieldVarying::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceSectionFieldVarying> &) const) &RWStepElement_RWSurfaceSectionFieldVarying::WriteStep, "Writes SurfaceSectionFieldVarying", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSectionFieldVarying.def("Share", (void (RWStepElement_RWSurfaceSectionFieldVarying::*)(const opencascade::handle<StepElement_SurfaceSectionFieldVarying> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceSectionFieldVarying::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWUNIFORMSURFACESECTION
py::class_<RWStepElement_RWUniformSurfaceSection> cls_RWStepElement_RWUniformSurfaceSection(mod, "RWStepElement_RWUniformSurfaceSection", "Read & Write tool for UniformSurfaceSection");

// Constructors
cls_RWStepElement_RWUniformSurfaceSection.def(py::init<>());

// Methods
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWUniformSurfaceSection::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWUniformSurfaceSection::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWUniformSurfaceSection::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWUniformSurfaceSection::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWUniformSurfaceSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWUniformSurfaceSection.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWUniformSurfaceSection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWUniformSurfaceSection.def("ReadStep", (void (RWStepElement_RWUniformSurfaceSection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_UniformSurfaceSection> &) const) &RWStepElement_RWUniformSurfaceSection::ReadStep, "Reads UniformSurfaceSection", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWUniformSurfaceSection.def("WriteStep", (void (RWStepElement_RWUniformSurfaceSection::*)(StepData_StepWriter &, const opencascade::handle<StepElement_UniformSurfaceSection> &) const) &RWStepElement_RWUniformSurfaceSection::WriteStep, "Writes UniformSurfaceSection", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWUniformSurfaceSection.def("Share", (void (RWStepElement_RWUniformSurfaceSection::*)(const opencascade::handle<StepElement_UniformSurfaceSection> &, Interface_EntityIterator &) const) &RWStepElement_RWUniformSurfaceSection::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPELEMENT_RWVOLUME3DELEMENTDESCRIPTOR
py::class_<RWStepElement_RWVolume3dElementDescriptor> cls_RWStepElement_RWVolume3dElementDescriptor(mod, "RWStepElement_RWVolume3dElementDescriptor", "Read & Write tool for Volume3dElementDescriptor");

// Constructors
cls_RWStepElement_RWVolume3dElementDescriptor.def(py::init<>());

// Methods
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWVolume3dElementDescriptor::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWVolume3dElementDescriptor::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWVolume3dElementDescriptor::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWVolume3dElementDescriptor::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWVolume3dElementDescriptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWVolume3dElementDescriptor.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWVolume3dElementDescriptor::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWVolume3dElementDescriptor.def("ReadStep", (void (RWStepElement_RWVolume3dElementDescriptor::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_Volume3dElementDescriptor> &) const) &RWStepElement_RWVolume3dElementDescriptor::ReadStep, "Reads Volume3dElementDescriptor", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWVolume3dElementDescriptor.def("WriteStep", (void (RWStepElement_RWVolume3dElementDescriptor::*)(StepData_StepWriter &, const opencascade::handle<StepElement_Volume3dElementDescriptor> &) const) &RWStepElement_RWVolume3dElementDescriptor::WriteStep, "Writes Volume3dElementDescriptor", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWVolume3dElementDescriptor.def("Share", (void (RWStepElement_RWVolume3dElementDescriptor::*)(const opencascade::handle<StepElement_Volume3dElementDescriptor> &, Interface_EntityIterator &) const) &RWStepElement_RWVolume3dElementDescriptor::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
