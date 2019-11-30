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
#include <StepElement_ElementVolume.hxx>
#include <StepElement_CurveEdge.hxx>
#include <StepElement_EnumeratedCurveElementFreedom.hxx>
#include <StepElement_UnspecifiedValue.hxx>
#include <StepElement_EnumeratedVolumeElementPurpose.hxx>
#include <StepElement_EnumeratedSurfaceElementPurpose.hxx>
#include <StepElement_ElementOrder.hxx>
#include <StepElement_EnumeratedCurveElementPurpose.hxx>
#include <StepElement_Element2dShape.hxx>
#include <StepElement_Volume3dElementShape.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfMaterialPropertyRepresentation.hxx>
#include <Standard_Std.hxx>
#include <StepElement_ElementMaterial.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <StepElement_SequenceOfElementMaterial.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepElement_HSequenceOfElementMaterial.hxx>
#include <StepData_SelectType.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_SelectMember.hxx>
#include <StepElement_ElementAspect.hxx>
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <StepElement_SequenceOfCurveElementSectionDefinition.hxx>
#include <StepElement_HSequenceOfCurveElementSectionDefinition.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_Representation.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepElement_CurveElementFreedom.hxx>
#include <StepElement_CurveElementEndReleasePacket.hxx>
#include <NCollection_Array1.hxx>
#include <StepElement_Array1OfCurveElementEndReleasePacket.hxx>
#include <StepElement_Array1OfCurveElementSectionDefinition.hxx>
#include <StepData_SelectNamed.hxx>
#include <StepElement_CurveElementPurposeMember.hxx>
#include <StepElement_SequenceOfCurveElementPurposeMember.hxx>
#include <StepElement_HSequenceOfCurveElementPurposeMember.hxx>
#include <StepElement_Array1OfHSequenceOfCurveElementPurposeMember.hxx>
#include <StepElement_SurfaceElementPurposeMember.hxx>
#include <StepElement_SequenceOfSurfaceElementPurposeMember.hxx>
#include <StepElement_HSequenceOfSurfaceElementPurposeMember.hxx>
#include <StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <StepElement_Array1OfMeasureOrUnspecifiedValue.hxx>
#include <StepElement_SurfaceSection.hxx>
#include <StepElement_Array1OfSurfaceSection.hxx>
#include <StepElement_VolumeElementPurpose.hxx>
#include <StepElement_Array1OfVolumeElementPurpose.hxx>
#include <StepElement_VolumeElementPurposeMember.hxx>
#include <StepElement_Array1OfVolumeElementPurposeMember.hxx>
#include <NCollection_Array2.hxx>
#include <StepElement_Array2OfCurveElementPurposeMember.hxx>
#include <StepElement_SurfaceElementPurpose.hxx>
#include <StepElement_Array2OfSurfaceElementPurpose.hxx>
#include <StepElement_Array2OfSurfaceElementPurposeMember.hxx>
#include <StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.hxx>
#include <StepElement_ElementDescriptor.hxx>
#include <StepElement_Curve3dElementDescriptor.hxx>
#include <StepElement_CurveElementFreedomMember.hxx>
#include <StepElement_CurveElementPurpose.hxx>
#include <StepElement_HArray1OfMeasureOrUnspecifiedValue.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepElement_CurveElementSectionDerivedDefinitions.hxx>
#include <StepElement_ElementAspectMember.hxx>
#include <StepElement_HArray1OfCurveElementEndReleasePacket.hxx>
#include <StepElement_HArray1OfCurveElementSectionDefinition.hxx>
#include <StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.hxx>
#include <StepElement_HArray1OfSurfaceSection.hxx>
#include <StepElement_HArray1OfVolumeElementPurpose.hxx>
#include <StepElement_HArray1OfVolumeElementPurposeMember.hxx>
#include <StepElement_HArray2OfCurveElementPurposeMember.hxx>
#include <StepElement_HArray2OfSurfaceElementPurpose.hxx>
#include <StepElement_HArray2OfSurfaceElementPurposeMember.hxx>
#include <StepElement_MeasureOrUnspecifiedValueMember.hxx>
#include <StepElement_Surface3dElementDescriptor.hxx>
#include <StepElement_SurfaceSectionField.hxx>
#include <StepElement_SurfaceElementProperty.hxx>
#include <StepElement_SurfaceSectionFieldConstant.hxx>
#include <StepElement_SurfaceSectionFieldVarying.hxx>
#include <StepElement_UniformSurfaceSection.hxx>
#include <StepElement_Volume3dElementDescriptor.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(StepElement, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TColStd");

// ENUM: STEPELEMENT_ELEMENTVOLUME
py::enum_<StepElement_ElementVolume>(mod, "StepElement_ElementVolume", "None")
	.value("StepElement_Volume", StepElement_ElementVolume::StepElement_Volume)
	.export_values();


// ENUM: STEPELEMENT_CURVEEDGE
py::enum_<StepElement_CurveEdge>(mod, "StepElement_CurveEdge", "None")
	.value("StepElement_ElementEdge", StepElement_CurveEdge::StepElement_ElementEdge)
	.export_values();


// ENUM: STEPELEMENT_ENUMERATEDCURVEELEMENTFREEDOM
py::enum_<StepElement_EnumeratedCurveElementFreedom>(mod, "StepElement_EnumeratedCurveElementFreedom", "None")
	.value("StepElement_XTranslation", StepElement_EnumeratedCurveElementFreedom::StepElement_XTranslation)
	.value("StepElement_YTranslation", StepElement_EnumeratedCurveElementFreedom::StepElement_YTranslation)
	.value("StepElement_ZTranslation", StepElement_EnumeratedCurveElementFreedom::StepElement_ZTranslation)
	.value("StepElement_XRotation", StepElement_EnumeratedCurveElementFreedom::StepElement_XRotation)
	.value("StepElement_YRotation", StepElement_EnumeratedCurveElementFreedom::StepElement_YRotation)
	.value("StepElement_ZRotation", StepElement_EnumeratedCurveElementFreedom::StepElement_ZRotation)
	.value("StepElement_Warp", StepElement_EnumeratedCurveElementFreedom::StepElement_Warp)
	.value("StepElement_None", StepElement_EnumeratedCurveElementFreedom::StepElement_None)
	.export_values();


// ENUM: STEPELEMENT_UNSPECIFIEDVALUE
py::enum_<StepElement_UnspecifiedValue>(mod, "StepElement_UnspecifiedValue", "None")
	.value("StepElement_Unspecified", StepElement_UnspecifiedValue::StepElement_Unspecified)
	.export_values();


// ENUM: STEPELEMENT_ENUMERATEDVOLUMEELEMENTPURPOSE
py::enum_<StepElement_EnumeratedVolumeElementPurpose>(mod, "StepElement_EnumeratedVolumeElementPurpose", "None")
	.value("StepElement_StressDisplacement", StepElement_EnumeratedVolumeElementPurpose::StepElement_StressDisplacement)
	.export_values();


// ENUM: STEPELEMENT_ENUMERATEDSURFACEELEMENTPURPOSE
py::enum_<StepElement_EnumeratedSurfaceElementPurpose>(mod, "StepElement_EnumeratedSurfaceElementPurpose", "None")
	.value("StepElement_MembraneDirect", StepElement_EnumeratedSurfaceElementPurpose::StepElement_MembraneDirect)
	.value("StepElement_MembraneShear", StepElement_EnumeratedSurfaceElementPurpose::StepElement_MembraneShear)
	.value("StepElement_BendingDirect", StepElement_EnumeratedSurfaceElementPurpose::StepElement_BendingDirect)
	.value("StepElement_BendingTorsion", StepElement_EnumeratedSurfaceElementPurpose::StepElement_BendingTorsion)
	.value("StepElement_NormalToPlaneShear", StepElement_EnumeratedSurfaceElementPurpose::StepElement_NormalToPlaneShear)
	.export_values();


// ENUM: STEPELEMENT_ELEMENTORDER
py::enum_<StepElement_ElementOrder>(mod, "StepElement_ElementOrder", "None")
	.value("StepElement_Linear", StepElement_ElementOrder::StepElement_Linear)
	.value("StepElement_Quadratic", StepElement_ElementOrder::StepElement_Quadratic)
	.value("StepElement_Cubic", StepElement_ElementOrder::StepElement_Cubic)
	.export_values();


// ENUM: STEPELEMENT_ENUMERATEDCURVEELEMENTPURPOSE
py::enum_<StepElement_EnumeratedCurveElementPurpose>(mod, "StepElement_EnumeratedCurveElementPurpose", "None")
	.value("StepElement_Axial", StepElement_EnumeratedCurveElementPurpose::StepElement_Axial)
	.value("StepElement_YYBending", StepElement_EnumeratedCurveElementPurpose::StepElement_YYBending)
	.value("StepElement_ZZBending", StepElement_EnumeratedCurveElementPurpose::StepElement_ZZBending)
	.value("StepElement_Torsion", StepElement_EnumeratedCurveElementPurpose::StepElement_Torsion)
	.value("StepElement_XYShear", StepElement_EnumeratedCurveElementPurpose::StepElement_XYShear)
	.value("StepElement_XZShear", StepElement_EnumeratedCurveElementPurpose::StepElement_XZShear)
	.value("StepElement_Warping", StepElement_EnumeratedCurveElementPurpose::StepElement_Warping)
	.export_values();


// ENUM: STEPELEMENT_ELEMENT2DSHAPE
py::enum_<StepElement_Element2dShape>(mod, "StepElement_Element2dShape", "None")
	.value("StepElement_Quadrilateral", StepElement_Element2dShape::StepElement_Quadrilateral)
	.value("StepElement_Triangle", StepElement_Element2dShape::StepElement_Triangle)
	.export_values();


// ENUM: STEPELEMENT_VOLUME3DELEMENTSHAPE
py::enum_<StepElement_Volume3dElementShape>(mod, "StepElement_Volume3dElementShape", "None")
	.value("StepElement_Hexahedron", StepElement_Volume3dElementShape::StepElement_Hexahedron)
	.value("StepElement_Wedge", StepElement_Volume3dElementShape::StepElement_Wedge)
	.value("StepElement_Tetrahedron", StepElement_Volume3dElementShape::StepElement_Tetrahedron)
	.value("StepElement_Pyramid", StepElement_Volume3dElementShape::StepElement_Pyramid)
	.export_values();


// CLASS: STEPELEMENT_ELEMENTMATERIAL
py::class_<StepElement_ElementMaterial, opencascade::handle<StepElement_ElementMaterial>, Standard_Transient> cls_StepElement_ElementMaterial(mod, "StepElement_ElementMaterial", "Representation of STEP entity ElementMaterial");

// Constructors
cls_StepElement_ElementMaterial.def(py::init<>());

// Methods
cls_StepElement_ElementMaterial.def("Init", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> &)) &StepElement_ElementMaterial::Init, "Initialize all fields (own and inherited)", py::arg("aMaterialId"), py::arg("aDescription"), py::arg("aProperties"));
cls_StepElement_ElementMaterial.def("MaterialId", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::MaterialId, "Returns field MaterialId");
cls_StepElement_ElementMaterial.def("SetMaterialId", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementMaterial::SetMaterialId, "Set field MaterialId", py::arg("MaterialId"));
cls_StepElement_ElementMaterial.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::Description, "Returns field Description");
cls_StepElement_ElementMaterial.def("SetDescription", (void (StepElement_ElementMaterial::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementMaterial::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_ElementMaterial.def("Properties", (opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::Properties, "Returns field Properties");
cls_StepElement_ElementMaterial.def("SetProperties", (void (StepElement_ElementMaterial::*)(const opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation> &)) &StepElement_ElementMaterial::SetProperties, "Set field Properties", py::arg("Properties"));
cls_StepElement_ElementMaterial.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementMaterial::get_type_name, "None");
cls_StepElement_ElementMaterial.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementMaterial::get_type_descriptor, "None");
cls_StepElement_ElementMaterial.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementMaterial::*)() const) &StepElement_ElementMaterial::DynamicType, "None");

// TYPEDEF: STEPELEMENT_SEQUENCEOFELEMENTMATERIAL
bind_NCollection_Sequence<opencascade::handle<StepElement_ElementMaterial> >(mod, "StepElement_SequenceOfElementMaterial", py::module_local(false));

// CLASS: STEPELEMENT_HSEQUENCEOFELEMENTMATERIAL
py::class_<StepElement_HSequenceOfElementMaterial, opencascade::handle<StepElement_HSequenceOfElementMaterial>, Standard_Transient> cls_StepElement_HSequenceOfElementMaterial(mod, "StepElement_HSequenceOfElementMaterial", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfElementMaterial.def(py::init<>());
cls_StepElement_HSequenceOfElementMaterial.def(py::init<const StepElement_SequenceOfElementMaterial &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfElementMaterial::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfElementMaterial::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfElementMaterial::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfElementMaterial::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfElementMaterial::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfElementMaterial::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfElementMaterial::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfElementMaterial.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfElementMaterial::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfElementMaterial.def("Sequence", (const StepElement_SequenceOfElementMaterial & (StepElement_HSequenceOfElementMaterial::*)() const) &StepElement_HSequenceOfElementMaterial::Sequence, "None");
cls_StepElement_HSequenceOfElementMaterial.def("Append", (void (StepElement_HSequenceOfElementMaterial::*)(const StepElement_SequenceOfElementMaterial::value_type &)) &StepElement_HSequenceOfElementMaterial::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfElementMaterial.def("Append", (void (StepElement_HSequenceOfElementMaterial::*)(StepElement_SequenceOfElementMaterial &)) &StepElement_HSequenceOfElementMaterial::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfElementMaterial.def("ChangeSequence", (StepElement_SequenceOfElementMaterial & (StepElement_HSequenceOfElementMaterial::*)()) &StepElement_HSequenceOfElementMaterial::ChangeSequence, "None");
cls_StepElement_HSequenceOfElementMaterial.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfElementMaterial::get_type_name, "None");
cls_StepElement_HSequenceOfElementMaterial.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfElementMaterial::get_type_descriptor, "None");
cls_StepElement_HSequenceOfElementMaterial.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfElementMaterial::*)() const) &StepElement_HSequenceOfElementMaterial::DynamicType, "None");

// CLASS: STEPELEMENT_ELEMENTASPECT
py::class_<StepElement_ElementAspect, StepData_SelectType> cls_StepElement_ElementAspect(mod, "StepElement_ElementAspect", "Representation of STEP SELECT type ElementAspect");

// Constructors
cls_StepElement_ElementAspect.def(py::init<>());

// Methods
// cls_StepElement_ElementAspect.def_static("operator new_", (void * (*)(size_t)) &StepElement_ElementAspect::operator new, "None", py::arg("theSize"));
// cls_StepElement_ElementAspect.def_static("operator delete_", (void (*)(void *)) &StepElement_ElementAspect::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_ElementAspect::operator new[], "None", py::arg("theSize"));
// cls_StepElement_ElementAspect.def_static("operator delete[]_", (void (*)(void *)) &StepElement_ElementAspect::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_ElementAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_ElementAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_ElementAspect.def("CaseNum", (Standard_Integer (StepElement_ElementAspect::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_ElementAspect::CaseNum, "Recognizes a kind of ElementAspect select type return 0", py::arg("ent"));
cls_StepElement_ElementAspect.def("CaseMem", (Standard_Integer (StepElement_ElementAspect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_ElementAspect::CaseMem, "Recognizes a items of select member ElementAspectMember 1 -> ElementVolume 2 -> Volume3dFace 3 -> Volume2dFace 4 -> Volume3dEdge 5 -> Volume2dEdge 6 -> Surface3dFace 7 -> Surface2dFace 8 -> Surface3dEdge 9 -> Surface2dEdge 10 -> CurveEdge 0 else", py::arg("ent"));
cls_StepElement_ElementAspect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::NewMember, "Returns a new select member the type ElementAspectMember");
cls_StepElement_ElementAspect.def("SetElementVolume", (void (StepElement_ElementAspect::*)(const StepElement_ElementVolume)) &StepElement_ElementAspect::SetElementVolume, "Set Value for ElementVolume", py::arg("aVal"));
cls_StepElement_ElementAspect.def("ElementVolume", (StepElement_ElementVolume (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::ElementVolume, "Returns Value as ElementVolume (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume3dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume3dFace, "Set Value for Volume3dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume3dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume3dFace, "Returns Value as Volume3dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume2dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume2dFace, "Set Value for Volume2dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume2dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume2dFace, "Returns Value as Volume2dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume3dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume3dEdge, "Set Value for Volume3dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume3dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume3dEdge, "Returns Value as Volume3dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume2dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume2dEdge, "Set Value for Volume2dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume2dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume2dEdge, "Returns Value as Volume2dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface3dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface3dFace, "Set Value for Surface3dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface3dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface3dFace, "Returns Value as Surface3dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface2dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface2dFace, "Set Value for Surface2dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface2dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface2dFace, "Returns Value as Surface2dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface3dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface3dEdge, "Set Value for Surface3dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface3dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface3dEdge, "Returns Value as Surface3dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface2dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface2dEdge, "Set Value for Surface2dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface2dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface2dEdge, "Returns Value as Surface2dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetCurveEdge", (void (StepElement_ElementAspect::*)(const StepElement_CurveEdge)) &StepElement_ElementAspect::SetCurveEdge, "Set Value for CurveEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("CurveEdge", (StepElement_CurveEdge (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::CurveEdge, "Returns Value as CurveEdge (or Null if another type)");

// CLASS: STEPELEMENT_CURVEELEMENTSECTIONDEFINITION
py::class_<StepElement_CurveElementSectionDefinition, opencascade::handle<StepElement_CurveElementSectionDefinition>, Standard_Transient> cls_StepElement_CurveElementSectionDefinition(mod, "StepElement_CurveElementSectionDefinition", "Representation of STEP entity CurveElementSectionDefinition");

// Constructors
cls_StepElement_CurveElementSectionDefinition.def(py::init<>());

// Methods
cls_StepElement_CurveElementSectionDefinition.def("Init", (void (StepElement_CurveElementSectionDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepElement_CurveElementSectionDefinition::Init, "Initialize all fields (own and inherited)", py::arg("aDescription"), py::arg("aSectionAngle"));
cls_StepElement_CurveElementSectionDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::Description, "Returns field Description");
cls_StepElement_CurveElementSectionDefinition.def("SetDescription", (void (StepElement_CurveElementSectionDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_CurveElementSectionDefinition::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_CurveElementSectionDefinition.def("SectionAngle", (Standard_Real (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::SectionAngle, "Returns field SectionAngle");
cls_StepElement_CurveElementSectionDefinition.def("SetSectionAngle", (void (StepElement_CurveElementSectionDefinition::*)(const Standard_Real)) &StepElement_CurveElementSectionDefinition::SetSectionAngle, "Set field SectionAngle", py::arg("SectionAngle"));
cls_StepElement_CurveElementSectionDefinition.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementSectionDefinition::get_type_name, "None");
cls_StepElement_CurveElementSectionDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementSectionDefinition::get_type_descriptor, "None");
cls_StepElement_CurveElementSectionDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::DynamicType, "None");

// TYPEDEF: STEPELEMENT_SEQUENCEOFCURVEELEMENTSECTIONDEFINITION
bind_NCollection_Sequence<opencascade::handle<StepElement_CurveElementSectionDefinition> >(mod, "StepElement_SequenceOfCurveElementSectionDefinition", py::module_local(false));

// CLASS: STEPELEMENT_HSEQUENCEOFCURVEELEMENTSECTIONDEFINITION
py::class_<StepElement_HSequenceOfCurveElementSectionDefinition, opencascade::handle<StepElement_HSequenceOfCurveElementSectionDefinition>, Standard_Transient> cls_StepElement_HSequenceOfCurveElementSectionDefinition(mod, "StepElement_HSequenceOfCurveElementSectionDefinition", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def(py::init<>());
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def(py::init<const StepElement_SequenceOfCurveElementSectionDefinition &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementSectionDefinition::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def("Sequence", (const StepElement_SequenceOfCurveElementSectionDefinition & (StepElement_HSequenceOfCurveElementSectionDefinition::*)() const) &StepElement_HSequenceOfCurveElementSectionDefinition::Sequence, "None");
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def("Append", (void (StepElement_HSequenceOfCurveElementSectionDefinition::*)(const StepElement_SequenceOfCurveElementSectionDefinition::value_type &)) &StepElement_HSequenceOfCurveElementSectionDefinition::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def("Append", (void (StepElement_HSequenceOfCurveElementSectionDefinition::*)(StepElement_SequenceOfCurveElementSectionDefinition &)) &StepElement_HSequenceOfCurveElementSectionDefinition::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def("ChangeSequence", (StepElement_SequenceOfCurveElementSectionDefinition & (StepElement_HSequenceOfCurveElementSectionDefinition::*)()) &StepElement_HSequenceOfCurveElementSectionDefinition::ChangeSequence, "None");
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfCurveElementSectionDefinition::get_type_name, "None");
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfCurveElementSectionDefinition::get_type_descriptor, "None");
cls_StepElement_HSequenceOfCurveElementSectionDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfCurveElementSectionDefinition::*)() const) &StepElement_HSequenceOfCurveElementSectionDefinition::DynamicType, "None");

// CLASS: STEPELEMENT_ANALYSISITEMWITHINREPRESENTATION
py::class_<StepElement_AnalysisItemWithinRepresentation, opencascade::handle<StepElement_AnalysisItemWithinRepresentation>, Standard_Transient> cls_StepElement_AnalysisItemWithinRepresentation(mod, "StepElement_AnalysisItemWithinRepresentation", "Representation of STEP entity AnalysisItemWithinRepresentation");

// Constructors
cls_StepElement_AnalysisItemWithinRepresentation.def(py::init<>());

// Methods
cls_StepElement_AnalysisItemWithinRepresentation.def("Init", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_Representation> &)) &StepElement_AnalysisItemWithinRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aItem"), py::arg("aRep"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Name, "Returns field Name");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetName", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_AnalysisItemWithinRepresentation::SetName, "Set field Name", py::arg("Name"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Description, "Returns field Description");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetDescription", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_AnalysisItemWithinRepresentation::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Item", (opencascade::handle<StepRepr_RepresentationItem> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Item, "Returns field Item");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetItem", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepElement_AnalysisItemWithinRepresentation::SetItem, "Set field Item", py::arg("Item"));
cls_StepElement_AnalysisItemWithinRepresentation.def("Rep", (opencascade::handle<StepRepr_Representation> (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::Rep, "Returns field Rep");
cls_StepElement_AnalysisItemWithinRepresentation.def("SetRep", (void (StepElement_AnalysisItemWithinRepresentation::*)(const opencascade::handle<StepRepr_Representation> &)) &StepElement_AnalysisItemWithinRepresentation::SetRep, "Set field Rep", py::arg("Rep"));
cls_StepElement_AnalysisItemWithinRepresentation.def_static("get_type_name_", (const char * (*)()) &StepElement_AnalysisItemWithinRepresentation::get_type_name, "None");
cls_StepElement_AnalysisItemWithinRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_AnalysisItemWithinRepresentation::get_type_descriptor, "None");
cls_StepElement_AnalysisItemWithinRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_AnalysisItemWithinRepresentation::*)() const) &StepElement_AnalysisItemWithinRepresentation::DynamicType, "None");

// CLASS: STEPELEMENT_CURVEELEMENTFREEDOM
py::class_<StepElement_CurveElementFreedom, StepData_SelectType> cls_StepElement_CurveElementFreedom(mod, "StepElement_CurveElementFreedom", "Representation of STEP SELECT type CurveElementFreedom");

// Constructors
cls_StepElement_CurveElementFreedom.def(py::init<>());

// Methods
// cls_StepElement_CurveElementFreedom.def_static("operator new_", (void * (*)(size_t)) &StepElement_CurveElementFreedom::operator new, "None", py::arg("theSize"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete_", (void (*)(void *)) &StepElement_CurveElementFreedom::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_CurveElementFreedom::operator new[], "None", py::arg("theSize"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete[]_", (void (*)(void *)) &StepElement_CurveElementFreedom::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_CurveElementFreedom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_CurveElementFreedom::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_CurveElementFreedom.def("CaseNum", (Standard_Integer (StepElement_CurveElementFreedom::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_CurveElementFreedom::CaseNum, "Recognizes a kind of CurveElementFreedom select type return 0", py::arg("ent"));
cls_StepElement_CurveElementFreedom.def("CaseMem", (Standard_Integer (StepElement_CurveElementFreedom::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_CurveElementFreedom::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> EnumeratedCurveElementFreedom 2 -> ApplicationDefinedDegreeOfFreedom 0 else", py::arg("ent"));
cls_StepElement_CurveElementFreedom.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::NewMember, "Returns a new select member the type CurveElementFreedomMember");
cls_StepElement_CurveElementFreedom.def("SetEnumeratedCurveElementFreedom", (void (StepElement_CurveElementFreedom::*)(const StepElement_EnumeratedCurveElementFreedom)) &StepElement_CurveElementFreedom::SetEnumeratedCurveElementFreedom, "Set Value for EnumeratedCurveElementFreedom", py::arg("aVal"));
cls_StepElement_CurveElementFreedom.def("EnumeratedCurveElementFreedom", (StepElement_EnumeratedCurveElementFreedom (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::EnumeratedCurveElementFreedom, "Returns Value as EnumeratedCurveElementFreedom (or Null if another type)");
cls_StepElement_CurveElementFreedom.def("SetApplicationDefinedDegreeOfFreedom", (void (StepElement_CurveElementFreedom::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_CurveElementFreedom::SetApplicationDefinedDegreeOfFreedom, "Set Value for ApplicationDefinedDegreeOfFreedom", py::arg("aVal"));
cls_StepElement_CurveElementFreedom.def("ApplicationDefinedDegreeOfFreedom", (opencascade::handle<TCollection_HAsciiString> (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::ApplicationDefinedDegreeOfFreedom, "Returns Value as ApplicationDefinedDegreeOfFreedom (or Null if another type)");

// CLASS: STEPELEMENT_CURVEELEMENTENDRELEASEPACKET
py::class_<StepElement_CurveElementEndReleasePacket, opencascade::handle<StepElement_CurveElementEndReleasePacket>, Standard_Transient> cls_StepElement_CurveElementEndReleasePacket(mod, "StepElement_CurveElementEndReleasePacket", "Representation of STEP entity CurveElementEndReleasePacket");

// Constructors
cls_StepElement_CurveElementEndReleasePacket.def(py::init<>());

// Methods
cls_StepElement_CurveElementEndReleasePacket.def("Init", (void (StepElement_CurveElementEndReleasePacket::*)(const StepElement_CurveElementFreedom &, const Standard_Real)) &StepElement_CurveElementEndReleasePacket::Init, "Initialize all fields (own and inherited)", py::arg("aReleaseFreedom"), py::arg("aReleaseStiffness"));
cls_StepElement_CurveElementEndReleasePacket.def("ReleaseFreedom", (StepElement_CurveElementFreedom (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::ReleaseFreedom, "Returns field ReleaseFreedom");
cls_StepElement_CurveElementEndReleasePacket.def("SetReleaseFreedom", (void (StepElement_CurveElementEndReleasePacket::*)(const StepElement_CurveElementFreedom &)) &StepElement_CurveElementEndReleasePacket::SetReleaseFreedom, "Set field ReleaseFreedom", py::arg("ReleaseFreedom"));
cls_StepElement_CurveElementEndReleasePacket.def("ReleaseStiffness", (Standard_Real (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::ReleaseStiffness, "Returns field ReleaseStiffness");
cls_StepElement_CurveElementEndReleasePacket.def("SetReleaseStiffness", (void (StepElement_CurveElementEndReleasePacket::*)(const Standard_Real)) &StepElement_CurveElementEndReleasePacket::SetReleaseStiffness, "Set field ReleaseStiffness", py::arg("ReleaseStiffness"));
cls_StepElement_CurveElementEndReleasePacket.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementEndReleasePacket::get_type_name, "None");
cls_StepElement_CurveElementEndReleasePacket.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementEndReleasePacket::get_type_descriptor, "None");
cls_StepElement_CurveElementEndReleasePacket.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::DynamicType, "None");

// TYPEDEF: STEPELEMENT_ARRAY1OFCURVEELEMENTENDRELEASEPACKET
bind_NCollection_Array1<opencascade::handle<StepElement_CurveElementEndReleasePacket> >(mod, "StepElement_Array1OfCurveElementEndReleasePacket", py::module_local(false));

// TYPEDEF: STEPELEMENT_ARRAY1OFCURVEELEMENTSECTIONDEFINITION
bind_NCollection_Array1<opencascade::handle<StepElement_CurveElementSectionDefinition> >(mod, "StepElement_Array1OfCurveElementSectionDefinition", py::module_local(false));

// CLASS: STEPELEMENT_CURVEELEMENTPURPOSEMEMBER
py::class_<StepElement_CurveElementPurposeMember, opencascade::handle<StepElement_CurveElementPurposeMember>, StepData_SelectNamed> cls_StepElement_CurveElementPurposeMember(mod, "StepElement_CurveElementPurposeMember", "Representation of member for STEP SELECT type CurveElementPurpose");

// Constructors
cls_StepElement_CurveElementPurposeMember.def(py::init<>());

// Methods
cls_StepElement_CurveElementPurposeMember.def("HasName", (Standard_Boolean (StepElement_CurveElementPurposeMember::*)() const) &StepElement_CurveElementPurposeMember::HasName, "Returns True if has name");
cls_StepElement_CurveElementPurposeMember.def("Name", (Standard_CString (StepElement_CurveElementPurposeMember::*)() const) &StepElement_CurveElementPurposeMember::Name, "Returns set name");
cls_StepElement_CurveElementPurposeMember.def("SetName", (Standard_Boolean (StepElement_CurveElementPurposeMember::*)(const Standard_CString)) &StepElement_CurveElementPurposeMember::SetName, "Set name", py::arg("name"));
cls_StepElement_CurveElementPurposeMember.def("Matches", (Standard_Boolean (StepElement_CurveElementPurposeMember::*)(const Standard_CString) const) &StepElement_CurveElementPurposeMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_CurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementPurposeMember::get_type_name, "None");
cls_StepElement_CurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_CurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementPurposeMember::*)() const) &StepElement_CurveElementPurposeMember::DynamicType, "None");

// TYPEDEF: STEPELEMENT_SEQUENCEOFCURVEELEMENTPURPOSEMEMBER
bind_NCollection_Sequence<opencascade::handle<StepElement_CurveElementPurposeMember> >(mod, "StepElement_SequenceOfCurveElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_HSEQUENCEOFCURVEELEMENTPURPOSEMEMBER
py::class_<StepElement_HSequenceOfCurveElementPurposeMember, opencascade::handle<StepElement_HSequenceOfCurveElementPurposeMember>, Standard_Transient> cls_StepElement_HSequenceOfCurveElementPurposeMember(mod, "StepElement_HSequenceOfCurveElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfCurveElementPurposeMember.def(py::init<>());
cls_StepElement_HSequenceOfCurveElementPurposeMember.def(py::init<const StepElement_SequenceOfCurveElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Sequence", (const StepElement_SequenceOfCurveElementPurposeMember & (StepElement_HSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HSequenceOfCurveElementPurposeMember::Sequence, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Append", (void (StepElement_HSequenceOfCurveElementPurposeMember::*)(const StepElement_SequenceOfCurveElementPurposeMember::value_type &)) &StepElement_HSequenceOfCurveElementPurposeMember::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Append", (void (StepElement_HSequenceOfCurveElementPurposeMember::*)(StepElement_SequenceOfCurveElementPurposeMember &)) &StepElement_HSequenceOfCurveElementPurposeMember::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("ChangeSequence", (StepElement_SequenceOfCurveElementPurposeMember & (StepElement_HSequenceOfCurveElementPurposeMember::*)()) &StepElement_HSequenceOfCurveElementPurposeMember::ChangeSequence, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfCurveElementPurposeMember::get_type_name, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfCurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HSequenceOfCurveElementPurposeMember::DynamicType, "None");

// TYPEDEF: STEPELEMENT_ARRAY1OFHSEQUENCEOFCURVEELEMENTPURPOSEMEMBER
bind_NCollection_Array1<opencascade::handle<StepElement_HSequenceOfCurveElementPurposeMember> >(mod, "StepElement_Array1OfHSequenceOfCurveElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_SURFACEELEMENTPURPOSEMEMBER
py::class_<StepElement_SurfaceElementPurposeMember, opencascade::handle<StepElement_SurfaceElementPurposeMember>, StepData_SelectNamed> cls_StepElement_SurfaceElementPurposeMember(mod, "StepElement_SurfaceElementPurposeMember", "Representation of member for STEP SELECT type SurfaceElementPurpose");

// Constructors
cls_StepElement_SurfaceElementPurposeMember.def(py::init<>());

// Methods
cls_StepElement_SurfaceElementPurposeMember.def("HasName", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::HasName, "Returns True if has name");
cls_StepElement_SurfaceElementPurposeMember.def("Name", (Standard_CString (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::Name, "Returns set name");
cls_StepElement_SurfaceElementPurposeMember.def("SetName", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)(const Standard_CString)) &StepElement_SurfaceElementPurposeMember::SetName, "Set name", py::arg("name"));
cls_StepElement_SurfaceElementPurposeMember.def("Matches", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)(const Standard_CString) const) &StepElement_SurfaceElementPurposeMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_SurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_SurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_SurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::DynamicType, "None");

// TYPEDEF: STEPELEMENT_SEQUENCEOFSURFACEELEMENTPURPOSEMEMBER
bind_NCollection_Sequence<opencascade::handle<StepElement_SurfaceElementPurposeMember> >(mod, "StepElement_SequenceOfSurfaceElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_HSEQUENCEOFSURFACEELEMENTPURPOSEMEMBER
py::class_<StepElement_HSequenceOfSurfaceElementPurposeMember, opencascade::handle<StepElement_HSequenceOfSurfaceElementPurposeMember>, Standard_Transient> cls_StepElement_HSequenceOfSurfaceElementPurposeMember(mod, "StepElement_HSequenceOfSurfaceElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def(py::init<>());
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def(py::init<const StepElement_SequenceOfSurfaceElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Sequence", (const StepElement_SequenceOfSurfaceElementPurposeMember & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HSequenceOfSurfaceElementPurposeMember::Sequence, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Append", (void (StepElement_HSequenceOfSurfaceElementPurposeMember::*)(const StepElement_SequenceOfSurfaceElementPurposeMember::value_type &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Append", (void (StepElement_HSequenceOfSurfaceElementPurposeMember::*)(StepElement_SequenceOfSurfaceElementPurposeMember &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("ChangeSequence", (StepElement_SequenceOfSurfaceElementPurposeMember & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::ChangeSequence, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HSequenceOfSurfaceElementPurposeMember::DynamicType, "None");

// TYPEDEF: STEPELEMENT_ARRAY1OFHSEQUENCEOFSURFACEELEMENTPURPOSEMEMBER
bind_NCollection_Array1<opencascade::handle<StepElement_HSequenceOfSurfaceElementPurposeMember> >(mod, "StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_MEASUREORUNSPECIFIEDVALUE
py::class_<StepElement_MeasureOrUnspecifiedValue, StepData_SelectType> cls_StepElement_MeasureOrUnspecifiedValue(mod, "StepElement_MeasureOrUnspecifiedValue", "Representation of STEP SELECT type MeasureOrUnspecifiedValue");

// Constructors
cls_StepElement_MeasureOrUnspecifiedValue.def(py::init<>());

// Methods
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t)) &StepElement_MeasureOrUnspecifiedValue::operator new, "None", py::arg("theSize"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_MeasureOrUnspecifiedValue::operator new[], "None", py::arg("theSize"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete[]_", (void (*)(void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_MeasureOrUnspecifiedValue::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_MeasureOrUnspecifiedValue.def("CaseNum", (Standard_Integer (StepElement_MeasureOrUnspecifiedValue::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_MeasureOrUnspecifiedValue::CaseNum, "Recognizes a kind of MeasureOrUnspecifiedValue select type return 0", py::arg("ent"));
cls_StepElement_MeasureOrUnspecifiedValue.def("CaseMem", (Standard_Integer (StepElement_MeasureOrUnspecifiedValue::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_MeasureOrUnspecifiedValue::CaseMem, "Recognizes a items of select member MeasureOrUnspecifiedValueMember 1 -> ContextDependentMeasure 2 -> UnspecifiedValue 0 else", py::arg("ent"));
cls_StepElement_MeasureOrUnspecifiedValue.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::NewMember, "Returns a new select member the type MeasureOrUnspecifiedValueMember");
cls_StepElement_MeasureOrUnspecifiedValue.def("SetContextDependentMeasure", (void (StepElement_MeasureOrUnspecifiedValue::*)(const Standard_Real)) &StepElement_MeasureOrUnspecifiedValue::SetContextDependentMeasure, "Set Value for ContextDependentMeasure", py::arg("aVal"));
cls_StepElement_MeasureOrUnspecifiedValue.def("ContextDependentMeasure", (Standard_Real (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::ContextDependentMeasure, "Returns Value as ContextDependentMeasure (or Null if another type)");
cls_StepElement_MeasureOrUnspecifiedValue.def("SetUnspecifiedValue", (void (StepElement_MeasureOrUnspecifiedValue::*)(const StepElement_UnspecifiedValue)) &StepElement_MeasureOrUnspecifiedValue::SetUnspecifiedValue, "Set Value for UnspecifiedValue", py::arg("aVal"));
cls_StepElement_MeasureOrUnspecifiedValue.def("UnspecifiedValue", (StepElement_UnspecifiedValue (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::UnspecifiedValue, "Returns Value as UnspecifiedValue (or Null if another type)");

// TYPEDEF: STEPELEMENT_ARRAY1OFMEASUREORUNSPECIFIEDVALUE
bind_NCollection_Array1<StepElement_MeasureOrUnspecifiedValue>(mod, "StepElement_Array1OfMeasureOrUnspecifiedValue", py::module_local(false));

// CLASS: STEPELEMENT_SURFACESECTION
py::class_<StepElement_SurfaceSection, opencascade::handle<StepElement_SurfaceSection>, Standard_Transient> cls_StepElement_SurfaceSection(mod, "StepElement_SurfaceSection", "Representation of STEP entity SurfaceSection");

// Constructors
cls_StepElement_SurfaceSection.def(py::init<>());

// Methods
cls_StepElement_SurfaceSection.def("Init", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::Init, "Initialize all fields (own and inherited)", py::arg("aOffset"), py::arg("aNonStructuralMass"), py::arg("aNonStructuralMassOffset"));
cls_StepElement_SurfaceSection.def("Offset", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::Offset, "Returns field Offset");
cls_StepElement_SurfaceSection.def("SetOffset", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetOffset, "Set field Offset", py::arg("Offset"));
cls_StepElement_SurfaceSection.def("NonStructuralMass", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::NonStructuralMass, "Returns field NonStructuralMass");
cls_StepElement_SurfaceSection.def("SetNonStructuralMass", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetNonStructuralMass, "Set field NonStructuralMass", py::arg("NonStructuralMass"));
cls_StepElement_SurfaceSection.def("NonStructuralMassOffset", (StepElement_MeasureOrUnspecifiedValue (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::NonStructuralMassOffset, "Returns field NonStructuralMassOffset");
cls_StepElement_SurfaceSection.def("SetNonStructuralMassOffset", (void (StepElement_SurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_SurfaceSection::SetNonStructuralMassOffset, "Set field NonStructuralMassOffset", py::arg("NonStructuralMassOffset"));
cls_StepElement_SurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSection::get_type_name, "None");
cls_StepElement_SurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSection::get_type_descriptor, "None");
cls_StepElement_SurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSection::*)() const) &StepElement_SurfaceSection::DynamicType, "None");

// TYPEDEF: STEPELEMENT_ARRAY1OFSURFACESECTION
bind_NCollection_Array1<opencascade::handle<StepElement_SurfaceSection> >(mod, "StepElement_Array1OfSurfaceSection", py::module_local(false));

// CLASS: STEPELEMENT_VOLUMEELEMENTPURPOSE
py::class_<StepElement_VolumeElementPurpose, StepData_SelectType> cls_StepElement_VolumeElementPurpose(mod, "StepElement_VolumeElementPurpose", "Representation of STEP SELECT type VolumeElementPurpose");

// Constructors
cls_StepElement_VolumeElementPurpose.def(py::init<>());

// Methods
// cls_StepElement_VolumeElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_VolumeElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_VolumeElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_VolumeElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_VolumeElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_VolumeElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_VolumeElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_VolumeElementPurpose.def("CaseNum", (Standard_Integer (StepElement_VolumeElementPurpose::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_VolumeElementPurpose::CaseNum, "Recognizes a kind of VolumeElementPurpose select type return 0", py::arg("ent"));
cls_StepElement_VolumeElementPurpose.def("CaseMem", (Standard_Integer (StepElement_VolumeElementPurpose::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_VolumeElementPurpose::CaseMem, "Recognizes a items of select member VolumeElementPurposeMember 1 -> EnumeratedVolumeElementPurpose 2 -> ApplicationDefinedElementPurpose 0 else", py::arg("ent"));
cls_StepElement_VolumeElementPurpose.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::NewMember, "Returns a new select member the type VolumeElementPurposeMember");
cls_StepElement_VolumeElementPurpose.def("SetEnumeratedVolumeElementPurpose", (void (StepElement_VolumeElementPurpose::*)(const StepElement_EnumeratedVolumeElementPurpose)) &StepElement_VolumeElementPurpose::SetEnumeratedVolumeElementPurpose, "Set Value for EnumeratedVolumeElementPurpose", py::arg("aVal"));
cls_StepElement_VolumeElementPurpose.def("EnumeratedVolumeElementPurpose", (StepElement_EnumeratedVolumeElementPurpose (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::EnumeratedVolumeElementPurpose, "Returns Value as EnumeratedVolumeElementPurpose (or Null if another type)");
cls_StepElement_VolumeElementPurpose.def("SetApplicationDefinedElementPurpose", (void (StepElement_VolumeElementPurpose::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_VolumeElementPurpose::SetApplicationDefinedElementPurpose, "Set Value for ApplicationDefinedElementPurpose", py::arg("aVal"));
cls_StepElement_VolumeElementPurpose.def("ApplicationDefinedElementPurpose", (opencascade::handle<TCollection_HAsciiString> (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::ApplicationDefinedElementPurpose, "Returns Value as ApplicationDefinedElementPurpose (or Null if another type)");

// TYPEDEF: STEPELEMENT_ARRAY1OFVOLUMEELEMENTPURPOSE
bind_NCollection_Array1<StepElement_VolumeElementPurpose>(mod, "StepElement_Array1OfVolumeElementPurpose", py::module_local(false));

// CLASS: STEPELEMENT_VOLUMEELEMENTPURPOSEMEMBER
py::class_<StepElement_VolumeElementPurposeMember, opencascade::handle<StepElement_VolumeElementPurposeMember>, StepData_SelectNamed> cls_StepElement_VolumeElementPurposeMember(mod, "StepElement_VolumeElementPurposeMember", "Representation of member for STEP SELECT type VolumeElementPurpose");

// Constructors
cls_StepElement_VolumeElementPurposeMember.def(py::init<>());

// Methods
cls_StepElement_VolumeElementPurposeMember.def("HasName", (Standard_Boolean (StepElement_VolumeElementPurposeMember::*)() const) &StepElement_VolumeElementPurposeMember::HasName, "Returns True if has name");
cls_StepElement_VolumeElementPurposeMember.def("Name", (Standard_CString (StepElement_VolumeElementPurposeMember::*)() const) &StepElement_VolumeElementPurposeMember::Name, "Returns set name");
cls_StepElement_VolumeElementPurposeMember.def("SetName", (Standard_Boolean (StepElement_VolumeElementPurposeMember::*)(const Standard_CString)) &StepElement_VolumeElementPurposeMember::SetName, "Set name", py::arg("name"));
cls_StepElement_VolumeElementPurposeMember.def("Matches", (Standard_Boolean (StepElement_VolumeElementPurposeMember::*)(const Standard_CString) const) &StepElement_VolumeElementPurposeMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_VolumeElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_VolumeElementPurposeMember::get_type_name, "None");
cls_StepElement_VolumeElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_VolumeElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_VolumeElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_VolumeElementPurposeMember::*)() const) &StepElement_VolumeElementPurposeMember::DynamicType, "None");

// TYPEDEF: STEPELEMENT_ARRAY1OFVOLUMEELEMENTPURPOSEMEMBER
bind_NCollection_Array1<opencascade::handle<StepElement_VolumeElementPurposeMember> >(mod, "StepElement_Array1OfVolumeElementPurposeMember", py::module_local(false));

// TYPEDEF: STEPELEMENT_ARRAY2OFCURVEELEMENTPURPOSEMEMBER
bind_NCollection_Array2<opencascade::handle<StepElement_CurveElementPurposeMember> >(mod, "StepElement_Array2OfCurveElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_SURFACEELEMENTPURPOSE
py::class_<StepElement_SurfaceElementPurpose, StepData_SelectType> cls_StepElement_SurfaceElementPurpose(mod, "StepElement_SurfaceElementPurpose", "Representation of STEP SELECT type SurfaceElementPurpose");

// Constructors
cls_StepElement_SurfaceElementPurpose.def(py::init<>());

// Methods
// cls_StepElement_SurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_SurfaceElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_SurfaceElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_SurfaceElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_SurfaceElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_SurfaceElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_SurfaceElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_SurfaceElementPurpose.def("CaseNum", (Standard_Integer (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_SurfaceElementPurpose::CaseNum, "Recognizes a kind of SurfaceElementPurpose select type return 0", py::arg("ent"));
cls_StepElement_SurfaceElementPurpose.def("CaseMem", (Standard_Integer (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_SurfaceElementPurpose::CaseMem, "Recognizes a items of select member SurfaceElementPurposeMember 1 -> EnumeratedSurfaceElementPurpose 2 -> ApplicationDefinedElementPurpose 0 else", py::arg("ent"));
cls_StepElement_SurfaceElementPurpose.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::NewMember, "Returns a new select member the type SurfaceElementPurposeMember");
cls_StepElement_SurfaceElementPurpose.def("SetEnumeratedSurfaceElementPurpose", (void (StepElement_SurfaceElementPurpose::*)(const StepElement_EnumeratedSurfaceElementPurpose)) &StepElement_SurfaceElementPurpose::SetEnumeratedSurfaceElementPurpose, "Set Value for EnumeratedSurfaceElementPurpose", py::arg("aVal"));
cls_StepElement_SurfaceElementPurpose.def("EnumeratedSurfaceElementPurpose", (StepElement_EnumeratedSurfaceElementPurpose (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::EnumeratedSurfaceElementPurpose, "Returns Value as EnumeratedSurfaceElementPurpose (or Null if another type)");
cls_StepElement_SurfaceElementPurpose.def("SetApplicationDefinedElementPurpose", (void (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementPurpose::SetApplicationDefinedElementPurpose, "Set Value for ApplicationDefinedElementPurpose", py::arg("aVal"));
cls_StepElement_SurfaceElementPurpose.def("ApplicationDefinedElementPurpose", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::ApplicationDefinedElementPurpose, "Returns Value as ApplicationDefinedElementPurpose (or Null if another type)");

// TYPEDEF: STEPELEMENT_ARRAY2OFSURFACEELEMENTPURPOSE
bind_NCollection_Array2<StepElement_SurfaceElementPurpose>(mod, "StepElement_Array2OfSurfaceElementPurpose", py::module_local(false));

// TYPEDEF: STEPELEMENT_ARRAY2OFSURFACEELEMENTPURPOSEMEMBER
bind_NCollection_Array2<opencascade::handle<StepElement_SurfaceElementPurposeMember> >(mod, "StepElement_Array2OfSurfaceElementPurposeMember", py::module_local(false));

// CLASS: STEPELEMENT_HARRAY1OFHSEQUENCEOFCURVEELEMENTPURPOSEMEMBER
py::class_<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember, opencascade::handle<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember>, Standard_Transient> cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember(mod, "StepElement_HArray1OfHSequenceOfCurveElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<>());
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfHSequenceOfCurveElementPurposeMember::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const StepElement_Array1OfHSequenceOfCurveElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("Array1", (const StepElement_Array1OfHSequenceOfCurveElementPurposeMember & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::Array1, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("ChangeArray1", (StepElement_Array1OfHSequenceOfCurveElementPurposeMember & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::ChangeArray1, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::DynamicType, "None");

// CLASS: STEPELEMENT_ELEMENTDESCRIPTOR
py::class_<StepElement_ElementDescriptor, opencascade::handle<StepElement_ElementDescriptor>, Standard_Transient> cls_StepElement_ElementDescriptor(mod, "StepElement_ElementDescriptor", "Representation of STEP entity ElementDescriptor");

// Constructors
cls_StepElement_ElementDescriptor.def(py::init<>());

// Methods
cls_StepElement_ElementDescriptor.def("Init", (void (StepElement_ElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aTopologyOrder"), py::arg("aDescription"));
cls_StepElement_ElementDescriptor.def("TopologyOrder", (StepElement_ElementOrder (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::TopologyOrder, "Returns field TopologyOrder");
cls_StepElement_ElementDescriptor.def("SetTopologyOrder", (void (StepElement_ElementDescriptor::*)(const StepElement_ElementOrder)) &StepElement_ElementDescriptor::SetTopologyOrder, "Set field TopologyOrder", py::arg("TopologyOrder"));
cls_StepElement_ElementDescriptor.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::Description, "Returns field Description");
cls_StepElement_ElementDescriptor.def("SetDescription", (void (StepElement_ElementDescriptor::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_ElementDescriptor::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_ElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementDescriptor::get_type_name, "None");
cls_StepElement_ElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementDescriptor::get_type_descriptor, "None");
cls_StepElement_ElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementDescriptor::*)() const) &StepElement_ElementDescriptor::DynamicType, "None");

// CLASS: STEPELEMENT_CURVE3DELEMENTDESCRIPTOR
py::class_<StepElement_Curve3dElementDescriptor, opencascade::handle<StepElement_Curve3dElementDescriptor>, StepElement_ElementDescriptor> cls_StepElement_Curve3dElementDescriptor(mod, "StepElement_Curve3dElementDescriptor", "Representation of STEP entity Curve3dElementDescriptor");

// Constructors
cls_StepElement_Curve3dElementDescriptor.def(py::init<>());

// Methods
cls_StepElement_Curve3dElementDescriptor.def("Init", (void (StepElement_Curve3dElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember> &)) &StepElement_Curve3dElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aElementDescriptor_TopologyOrder"), py::arg("aElementDescriptor_Description"), py::arg("aPurpose"));
cls_StepElement_Curve3dElementDescriptor.def("Purpose", (opencascade::handle<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember> (StepElement_Curve3dElementDescriptor::*)() const) &StepElement_Curve3dElementDescriptor::Purpose, "Returns field Purpose");
cls_StepElement_Curve3dElementDescriptor.def("SetPurpose", (void (StepElement_Curve3dElementDescriptor::*)(const opencascade::handle<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember> &)) &StepElement_Curve3dElementDescriptor::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepElement_Curve3dElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_Curve3dElementDescriptor::get_type_name, "None");
cls_StepElement_Curve3dElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_Curve3dElementDescriptor::get_type_descriptor, "None");
cls_StepElement_Curve3dElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_Curve3dElementDescriptor::*)() const) &StepElement_Curve3dElementDescriptor::DynamicType, "None");

// CLASS: STEPELEMENT_CURVEELEMENTFREEDOMMEMBER
py::class_<StepElement_CurveElementFreedomMember, opencascade::handle<StepElement_CurveElementFreedomMember>, StepData_SelectNamed> cls_StepElement_CurveElementFreedomMember(mod, "StepElement_CurveElementFreedomMember", "Representation of member for STEP SELECT type CurveElementFreedom");

// Constructors
cls_StepElement_CurveElementFreedomMember.def(py::init<>());

// Methods
cls_StepElement_CurveElementFreedomMember.def("HasName", (Standard_Boolean (StepElement_CurveElementFreedomMember::*)() const) &StepElement_CurveElementFreedomMember::HasName, "Returns True if has name");
cls_StepElement_CurveElementFreedomMember.def("Name", (Standard_CString (StepElement_CurveElementFreedomMember::*)() const) &StepElement_CurveElementFreedomMember::Name, "Returns set name");
cls_StepElement_CurveElementFreedomMember.def("SetName", (Standard_Boolean (StepElement_CurveElementFreedomMember::*)(const Standard_CString)) &StepElement_CurveElementFreedomMember::SetName, "Set name", py::arg("name"));
cls_StepElement_CurveElementFreedomMember.def("Matches", (Standard_Boolean (StepElement_CurveElementFreedomMember::*)(const Standard_CString) const) &StepElement_CurveElementFreedomMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_CurveElementFreedomMember.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementFreedomMember::get_type_name, "None");
cls_StepElement_CurveElementFreedomMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementFreedomMember::get_type_descriptor, "None");
cls_StepElement_CurveElementFreedomMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementFreedomMember::*)() const) &StepElement_CurveElementFreedomMember::DynamicType, "None");

// CLASS: STEPELEMENT_CURVEELEMENTPURPOSE
py::class_<StepElement_CurveElementPurpose, StepData_SelectType> cls_StepElement_CurveElementPurpose(mod, "StepElement_CurveElementPurpose", "Representation of STEP SELECT type CurveElementPurpose");

// Constructors
cls_StepElement_CurveElementPurpose.def(py::init<>());

// Methods
// cls_StepElement_CurveElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_CurveElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_CurveElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_CurveElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_CurveElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_CurveElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_CurveElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_CurveElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_CurveElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_CurveElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_CurveElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_CurveElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_CurveElementPurpose.def("CaseNum", (Standard_Integer (StepElement_CurveElementPurpose::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_CurveElementPurpose::CaseNum, "Recognizes a kind of CurveElementPurpose select type return 0", py::arg("ent"));
cls_StepElement_CurveElementPurpose.def("CaseMem", (Standard_Integer (StepElement_CurveElementPurpose::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_CurveElementPurpose::CaseMem, "Recognizes a items of select member CurveElementPurposeMember 1 -> EnumeratedCurveElementPurpose 2 -> ApplicationDefinedElementPurpose 0 else", py::arg("ent"));
cls_StepElement_CurveElementPurpose.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_CurveElementPurpose::*)() const) &StepElement_CurveElementPurpose::NewMember, "Returns a new select member the type CurveElementPurposeMember");
cls_StepElement_CurveElementPurpose.def("SetEnumeratedCurveElementPurpose", (void (StepElement_CurveElementPurpose::*)(const StepElement_EnumeratedCurveElementPurpose)) &StepElement_CurveElementPurpose::SetEnumeratedCurveElementPurpose, "Set Value for EnumeratedCurveElementPurpose", py::arg("aVal"));
cls_StepElement_CurveElementPurpose.def("EnumeratedCurveElementPurpose", (StepElement_EnumeratedCurveElementPurpose (StepElement_CurveElementPurpose::*)() const) &StepElement_CurveElementPurpose::EnumeratedCurveElementPurpose, "Returns Value as EnumeratedCurveElementPurpose (or Null if another type)");
cls_StepElement_CurveElementPurpose.def("SetApplicationDefinedElementPurpose", (void (StepElement_CurveElementPurpose::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_CurveElementPurpose::SetApplicationDefinedElementPurpose, "Set Value for ApplicationDefinedElementPurpose", py::arg("aVal"));
cls_StepElement_CurveElementPurpose.def("ApplicationDefinedElementPurpose", (opencascade::handle<TCollection_HAsciiString> (StepElement_CurveElementPurpose::*)() const) &StepElement_CurveElementPurpose::ApplicationDefinedElementPurpose, "Returns Value as ApplicationDefinedElementPurpose (or Null if another type)");

// CLASS: STEPELEMENT_HARRAY1OFMEASUREORUNSPECIFIEDVALUE
py::class_<StepElement_HArray1OfMeasureOrUnspecifiedValue, opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue>, Standard_Transient> cls_StepElement_HArray1OfMeasureOrUnspecifiedValue(mod, "StepElement_HArray1OfMeasureOrUnspecifiedValue", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def(py::init<>());
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfMeasureOrUnspecifiedValue::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def(py::init<const StepElement_Array1OfMeasureOrUnspecifiedValue &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfMeasureOrUnspecifiedValue::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def("Array1", (const StepElement_Array1OfMeasureOrUnspecifiedValue & (StepElement_HArray1OfMeasureOrUnspecifiedValue::*)() const) &StepElement_HArray1OfMeasureOrUnspecifiedValue::Array1, "None");
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def("ChangeArray1", (StepElement_Array1OfMeasureOrUnspecifiedValue & (StepElement_HArray1OfMeasureOrUnspecifiedValue::*)()) &StepElement_HArray1OfMeasureOrUnspecifiedValue::ChangeArray1, "None");
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfMeasureOrUnspecifiedValue::get_type_name, "None");
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfMeasureOrUnspecifiedValue::get_type_descriptor, "None");
cls_StepElement_HArray1OfMeasureOrUnspecifiedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfMeasureOrUnspecifiedValue::*)() const) &StepElement_HArray1OfMeasureOrUnspecifiedValue::DynamicType, "None");

// CLASS: STEPELEMENT_CURVEELEMENTSECTIONDERIVEDDEFINITIONS
py::class_<StepElement_CurveElementSectionDerivedDefinitions, opencascade::handle<StepElement_CurveElementSectionDerivedDefinitions>, StepElement_CurveElementSectionDefinition> cls_StepElement_CurveElementSectionDerivedDefinitions(mod, "StepElement_CurveElementSectionDerivedDefinitions", "Representation of STEP entity CurveElementSectionDerivedDefinitions");

// Constructors
cls_StepElement_CurveElementSectionDerivedDefinitions.def(py::init<>());

// Methods
cls_StepElement_CurveElementSectionDerivedDefinitions.def("Init", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const StepElement_MeasureOrUnspecifiedValue &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementSectionDefinition_Description"), py::arg("aCurveElementSectionDefinition_SectionAngle"), py::arg("aCrossSectionalArea"), py::arg("aShearArea"), py::arg("aSecondMomentOfArea"), py::arg("aTorsionalConstant"), py::arg("aWarpingConstant"), py::arg("aLocationOfCentroid"), py::arg("aLocationOfShearCentre"), py::arg("aLocationOfNonStructuralMass"), py::arg("aNonStructuralMass"), py::arg("aPolarMoment"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("CrossSectionalArea", (Standard_Real (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::CrossSectionalArea, "Returns field CrossSectionalArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetCrossSectionalArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const Standard_Real)) &StepElement_CurveElementSectionDerivedDefinitions::SetCrossSectionalArea, "Set field CrossSectionalArea", py::arg("CrossSectionalArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("ShearArea", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::ShearArea, "Returns field ShearArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetShearArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetShearArea, "Set field ShearArea", py::arg("ShearArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SecondMomentOfArea", (opencascade::handle<TColStd_HArray1OfReal> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::SecondMomentOfArea, "Returns field SecondMomentOfArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetSecondMomentOfArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetSecondMomentOfArea, "Set field SecondMomentOfArea", py::arg("SecondMomentOfArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("TorsionalConstant", (Standard_Real (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::TorsionalConstant, "Returns field TorsionalConstant");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetTorsionalConstant", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const Standard_Real)) &StepElement_CurveElementSectionDerivedDefinitions::SetTorsionalConstant, "Set field TorsionalConstant", py::arg("TorsionalConstant"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("WarpingConstant", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::WarpingConstant, "Returns field WarpingConstant");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetWarpingConstant", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetWarpingConstant, "Set field WarpingConstant", py::arg("WarpingConstant"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfCentroid", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfCentroid, "Returns field LocationOfCentroid");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfCentroid", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfCentroid, "Set field LocationOfCentroid", py::arg("LocationOfCentroid"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfShearCentre", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfShearCentre, "Returns field LocationOfShearCentre");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfShearCentre", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfShearCentre, "Set field LocationOfShearCentre", py::arg("LocationOfShearCentre"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfNonStructuralMass", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfNonStructuralMass, "Returns field LocationOfNonStructuralMass");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfNonStructuralMass", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfNonStructuralMass, "Set field LocationOfNonStructuralMass", py::arg("LocationOfNonStructuralMass"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("NonStructuralMass", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::NonStructuralMass, "Returns field NonStructuralMass");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetNonStructuralMass", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetNonStructuralMass, "Set field NonStructuralMass", py::arg("NonStructuralMass"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("PolarMoment", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::PolarMoment, "Returns field PolarMoment");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetPolarMoment", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetPolarMoment, "Set field PolarMoment", py::arg("PolarMoment"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementSectionDerivedDefinitions::get_type_name, "None");
cls_StepElement_CurveElementSectionDerivedDefinitions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementSectionDerivedDefinitions::get_type_descriptor, "None");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::DynamicType, "None");

// CLASS: STEPELEMENT_ELEMENTASPECTMEMBER
py::class_<StepElement_ElementAspectMember, opencascade::handle<StepElement_ElementAspectMember>, StepData_SelectNamed> cls_StepElement_ElementAspectMember(mod, "StepElement_ElementAspectMember", "Representation of member for STEP SELECT type ElementAspect");

// Constructors
cls_StepElement_ElementAspectMember.def(py::init<>());

// Methods
cls_StepElement_ElementAspectMember.def("HasName", (Standard_Boolean (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::HasName, "Returns True if has name");
cls_StepElement_ElementAspectMember.def("Name", (Standard_CString (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::Name, "Returns set name");
cls_StepElement_ElementAspectMember.def("SetName", (Standard_Boolean (StepElement_ElementAspectMember::*)(const Standard_CString)) &StepElement_ElementAspectMember::SetName, "Set name", py::arg("name"));
cls_StepElement_ElementAspectMember.def("Matches", (Standard_Boolean (StepElement_ElementAspectMember::*)(const Standard_CString) const) &StepElement_ElementAspectMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_ElementAspectMember.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementAspectMember::get_type_name, "None");
cls_StepElement_ElementAspectMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementAspectMember::get_type_descriptor, "None");
cls_StepElement_ElementAspectMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFCURVEELEMENTENDRELEASEPACKET
py::class_<StepElement_HArray1OfCurveElementEndReleasePacket, opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket>, Standard_Transient> cls_StepElement_HArray1OfCurveElementEndReleasePacket(mod, "StepElement_HArray1OfCurveElementEndReleasePacket", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def(py::init<>());
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfCurveElementEndReleasePacket::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def(py::init<const StepElement_Array1OfCurveElementEndReleasePacket &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfCurveElementEndReleasePacket::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def("Array1", (const StepElement_Array1OfCurveElementEndReleasePacket & (StepElement_HArray1OfCurveElementEndReleasePacket::*)() const) &StepElement_HArray1OfCurveElementEndReleasePacket::Array1, "None");
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def("ChangeArray1", (StepElement_Array1OfCurveElementEndReleasePacket & (StepElement_HArray1OfCurveElementEndReleasePacket::*)()) &StepElement_HArray1OfCurveElementEndReleasePacket::ChangeArray1, "None");
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfCurveElementEndReleasePacket::get_type_name, "None");
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfCurveElementEndReleasePacket::get_type_descriptor, "None");
cls_StepElement_HArray1OfCurveElementEndReleasePacket.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfCurveElementEndReleasePacket::*)() const) &StepElement_HArray1OfCurveElementEndReleasePacket::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFCURVEELEMENTSECTIONDEFINITION
py::class_<StepElement_HArray1OfCurveElementSectionDefinition, opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition>, Standard_Transient> cls_StepElement_HArray1OfCurveElementSectionDefinition(mod, "StepElement_HArray1OfCurveElementSectionDefinition", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfCurveElementSectionDefinition.def(py::init<>());
cls_StepElement_HArray1OfCurveElementSectionDefinition.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfCurveElementSectionDefinition.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfCurveElementSectionDefinition::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfCurveElementSectionDefinition.def(py::init<const StepElement_Array1OfCurveElementSectionDefinition &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfCurveElementSectionDefinition::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfCurveElementSectionDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfCurveElementSectionDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfCurveElementSectionDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfCurveElementSectionDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfCurveElementSectionDefinition::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfCurveElementSectionDefinition::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfCurveElementSectionDefinition::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfCurveElementSectionDefinition.def("Array1", (const StepElement_Array1OfCurveElementSectionDefinition & (StepElement_HArray1OfCurveElementSectionDefinition::*)() const) &StepElement_HArray1OfCurveElementSectionDefinition::Array1, "None");
cls_StepElement_HArray1OfCurveElementSectionDefinition.def("ChangeArray1", (StepElement_Array1OfCurveElementSectionDefinition & (StepElement_HArray1OfCurveElementSectionDefinition::*)()) &StepElement_HArray1OfCurveElementSectionDefinition::ChangeArray1, "None");
cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfCurveElementSectionDefinition::get_type_name, "None");
cls_StepElement_HArray1OfCurveElementSectionDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfCurveElementSectionDefinition::get_type_descriptor, "None");
cls_StepElement_HArray1OfCurveElementSectionDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfCurveElementSectionDefinition::*)() const) &StepElement_HArray1OfCurveElementSectionDefinition::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFHSEQUENCEOFSURFACEELEMENTPURPOSEMEMBER
py::class_<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember, opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember>, Standard_Transient> cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember(mod, "StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def(py::init<>());
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def(py::init<const StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def("Array1", (const StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember & (StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::Array1, "None");
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def("ChangeArray1", (StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember & (StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::*)()) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::ChangeArray1, "None");
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFSURFACESECTION
py::class_<StepElement_HArray1OfSurfaceSection, opencascade::handle<StepElement_HArray1OfSurfaceSection>, Standard_Transient> cls_StepElement_HArray1OfSurfaceSection(mod, "StepElement_HArray1OfSurfaceSection", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfSurfaceSection.def(py::init<>());
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfSurfaceSection::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const StepElement_Array1OfSurfaceSection &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfSurfaceSection::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfSurfaceSection::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfSurfaceSection.def("Array1", (const StepElement_Array1OfSurfaceSection & (StepElement_HArray1OfSurfaceSection::*)() const) &StepElement_HArray1OfSurfaceSection::Array1, "None");
cls_StepElement_HArray1OfSurfaceSection.def("ChangeArray1", (StepElement_Array1OfSurfaceSection & (StepElement_HArray1OfSurfaceSection::*)()) &StepElement_HArray1OfSurfaceSection::ChangeArray1, "None");
cls_StepElement_HArray1OfSurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfSurfaceSection::get_type_name, "None");
cls_StepElement_HArray1OfSurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfSurfaceSection::get_type_descriptor, "None");
cls_StepElement_HArray1OfSurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfSurfaceSection::*)() const) &StepElement_HArray1OfSurfaceSection::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFVOLUMEELEMENTPURPOSE
py::class_<StepElement_HArray1OfVolumeElementPurpose, opencascade::handle<StepElement_HArray1OfVolumeElementPurpose>, Standard_Transient> cls_StepElement_HArray1OfVolumeElementPurpose(mod, "StepElement_HArray1OfVolumeElementPurpose", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfVolumeElementPurpose.def(py::init<>());
cls_StepElement_HArray1OfVolumeElementPurpose.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfVolumeElementPurpose.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfVolumeElementPurpose::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfVolumeElementPurpose.def(py::init<const StepElement_Array1OfVolumeElementPurpose &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfVolumeElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfVolumeElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfVolumeElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfVolumeElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfVolumeElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfVolumeElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfVolumeElementPurpose::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfVolumeElementPurpose.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfVolumeElementPurpose::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfVolumeElementPurpose.def("Array1", (const StepElement_Array1OfVolumeElementPurpose & (StepElement_HArray1OfVolumeElementPurpose::*)() const) &StepElement_HArray1OfVolumeElementPurpose::Array1, "None");
cls_StepElement_HArray1OfVolumeElementPurpose.def("ChangeArray1", (StepElement_Array1OfVolumeElementPurpose & (StepElement_HArray1OfVolumeElementPurpose::*)()) &StepElement_HArray1OfVolumeElementPurpose::ChangeArray1, "None");
cls_StepElement_HArray1OfVolumeElementPurpose.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfVolumeElementPurpose::get_type_name, "None");
cls_StepElement_HArray1OfVolumeElementPurpose.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfVolumeElementPurpose::get_type_descriptor, "None");
cls_StepElement_HArray1OfVolumeElementPurpose.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfVolumeElementPurpose::*)() const) &StepElement_HArray1OfVolumeElementPurpose::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY1OFVOLUMEELEMENTPURPOSEMEMBER
py::class_<StepElement_HArray1OfVolumeElementPurposeMember, opencascade::handle<StepElement_HArray1OfVolumeElementPurposeMember>, Standard_Transient> cls_StepElement_HArray1OfVolumeElementPurposeMember(mod, "StepElement_HArray1OfVolumeElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfVolumeElementPurposeMember.def(py::init<>());
cls_StepElement_HArray1OfVolumeElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfVolumeElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfVolumeElementPurposeMember::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfVolumeElementPurposeMember.def(py::init<const StepElement_Array1OfVolumeElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfVolumeElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfVolumeElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfVolumeElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfVolumeElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfVolumeElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfVolumeElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfVolumeElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfVolumeElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfVolumeElementPurposeMember.def("Array1", (const StepElement_Array1OfVolumeElementPurposeMember & (StepElement_HArray1OfVolumeElementPurposeMember::*)() const) &StepElement_HArray1OfVolumeElementPurposeMember::Array1, "None");
cls_StepElement_HArray1OfVolumeElementPurposeMember.def("ChangeArray1", (StepElement_Array1OfVolumeElementPurposeMember & (StepElement_HArray1OfVolumeElementPurposeMember::*)()) &StepElement_HArray1OfVolumeElementPurposeMember::ChangeArray1, "None");
cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfVolumeElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray1OfVolumeElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfVolumeElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray1OfVolumeElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfVolumeElementPurposeMember::*)() const) &StepElement_HArray1OfVolumeElementPurposeMember::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY2OFCURVEELEMENTPURPOSEMEMBER
py::class_<StepElement_HArray2OfCurveElementPurposeMember, opencascade::handle<StepElement_HArray2OfCurveElementPurposeMember>, Standard_Transient> cls_StepElement_HArray2OfCurveElementPurposeMember(mod, "StepElement_HArray2OfCurveElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray2OfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StepElement_HArray2OfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const StepElement_Array2OfCurveElementPurposeMember::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StepElement_HArray2OfCurveElementPurposeMember.def(py::init<const StepElement_Array2OfCurveElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray2OfCurveElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray2OfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray2OfCurveElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray2OfCurveElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray2OfCurveElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray2OfCurveElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfCurveElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray2OfCurveElementPurposeMember.def("Array2", (const StepElement_Array2OfCurveElementPurposeMember & (StepElement_HArray2OfCurveElementPurposeMember::*)() const) &StepElement_HArray2OfCurveElementPurposeMember::Array2, "None");
cls_StepElement_HArray2OfCurveElementPurposeMember.def("ChangeArray2", (StepElement_Array2OfCurveElementPurposeMember & (StepElement_HArray2OfCurveElementPurposeMember::*)()) &StepElement_HArray2OfCurveElementPurposeMember::ChangeArray2, "None");
cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray2OfCurveElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray2OfCurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray2OfCurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray2OfCurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray2OfCurveElementPurposeMember::*)() const) &StepElement_HArray2OfCurveElementPurposeMember::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY2OFSURFACEELEMENTPURPOSE
py::class_<StepElement_HArray2OfSurfaceElementPurpose, opencascade::handle<StepElement_HArray2OfSurfaceElementPurpose>, Standard_Transient> cls_StepElement_HArray2OfSurfaceElementPurpose(mod, "StepElement_HArray2OfSurfaceElementPurpose", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray2OfSurfaceElementPurpose.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StepElement_HArray2OfSurfaceElementPurpose.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const StepElement_Array2OfSurfaceElementPurpose::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StepElement_HArray2OfSurfaceElementPurpose.def(py::init<const StepElement_Array2OfSurfaceElementPurpose &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray2OfSurfaceElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray2OfSurfaceElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurpose::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurpose::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray2OfSurfaceElementPurpose.def("Array2", (const StepElement_Array2OfSurfaceElementPurpose & (StepElement_HArray2OfSurfaceElementPurpose::*)() const) &StepElement_HArray2OfSurfaceElementPurpose::Array2, "None");
cls_StepElement_HArray2OfSurfaceElementPurpose.def("ChangeArray2", (StepElement_Array2OfSurfaceElementPurpose & (StepElement_HArray2OfSurfaceElementPurpose::*)()) &StepElement_HArray2OfSurfaceElementPurpose::ChangeArray2, "None");
cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray2OfSurfaceElementPurpose::get_type_name, "None");
cls_StepElement_HArray2OfSurfaceElementPurpose.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray2OfSurfaceElementPurpose::get_type_descriptor, "None");
cls_StepElement_HArray2OfSurfaceElementPurpose.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray2OfSurfaceElementPurpose::*)() const) &StepElement_HArray2OfSurfaceElementPurpose::DynamicType, "None");

// CLASS: STEPELEMENT_HARRAY2OFSURFACEELEMENTPURPOSEMEMBER
py::class_<StepElement_HArray2OfSurfaceElementPurposeMember, opencascade::handle<StepElement_HArray2OfSurfaceElementPurposeMember>, Standard_Transient> cls_StepElement_HArray2OfSurfaceElementPurposeMember(mod, "StepElement_HArray2OfSurfaceElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const StepElement_Array2OfSurfaceElementPurposeMember::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const StepElement_Array2OfSurfaceElementPurposeMember &>(), py::arg("theOther"));

// Methods
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("Array2", (const StepElement_Array2OfSurfaceElementPurposeMember & (StepElement_HArray2OfSurfaceElementPurposeMember::*)() const) &StepElement_HArray2OfSurfaceElementPurposeMember::Array2, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("ChangeArray2", (StepElement_Array2OfSurfaceElementPurposeMember & (StepElement_HArray2OfSurfaceElementPurposeMember::*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::ChangeArray2, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray2OfSurfaceElementPurposeMember::*)() const) &StepElement_HArray2OfSurfaceElementPurposeMember::DynamicType, "None");

// CLASS: STEPELEMENT_MEASUREORUNSPECIFIEDVALUEMEMBER
py::class_<StepElement_MeasureOrUnspecifiedValueMember, opencascade::handle<StepElement_MeasureOrUnspecifiedValueMember>, StepData_SelectNamed> cls_StepElement_MeasureOrUnspecifiedValueMember(mod, "StepElement_MeasureOrUnspecifiedValueMember", "Representation of member for STEP SELECT type MeasureOrUnspecifiedValue");

// Constructors
cls_StepElement_MeasureOrUnspecifiedValueMember.def(py::init<>());

// Methods
cls_StepElement_MeasureOrUnspecifiedValueMember.def("HasName", (Standard_Boolean (StepElement_MeasureOrUnspecifiedValueMember::*)() const) &StepElement_MeasureOrUnspecifiedValueMember::HasName, "Returns True if has name");
cls_StepElement_MeasureOrUnspecifiedValueMember.def("Name", (Standard_CString (StepElement_MeasureOrUnspecifiedValueMember::*)() const) &StepElement_MeasureOrUnspecifiedValueMember::Name, "Returns set name");
cls_StepElement_MeasureOrUnspecifiedValueMember.def("SetName", (Standard_Boolean (StepElement_MeasureOrUnspecifiedValueMember::*)(const Standard_CString)) &StepElement_MeasureOrUnspecifiedValueMember::SetName, "Set name", py::arg("name"));
cls_StepElement_MeasureOrUnspecifiedValueMember.def("Matches", (Standard_Boolean (StepElement_MeasureOrUnspecifiedValueMember::*)(const Standard_CString) const) &StepElement_MeasureOrUnspecifiedValueMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_MeasureOrUnspecifiedValueMember.def_static("get_type_name_", (const char * (*)()) &StepElement_MeasureOrUnspecifiedValueMember::get_type_name, "None");
cls_StepElement_MeasureOrUnspecifiedValueMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_MeasureOrUnspecifiedValueMember::get_type_descriptor, "None");
cls_StepElement_MeasureOrUnspecifiedValueMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_MeasureOrUnspecifiedValueMember::*)() const) &StepElement_MeasureOrUnspecifiedValueMember::DynamicType, "None");

// CLASS: STEPELEMENT_SURFACE3DELEMENTDESCRIPTOR
py::class_<StepElement_Surface3dElementDescriptor, opencascade::handle<StepElement_Surface3dElementDescriptor>, StepElement_ElementDescriptor> cls_StepElement_Surface3dElementDescriptor(mod, "StepElement_Surface3dElementDescriptor", "Representation of STEP entity Surface3dElementDescriptor");

// Constructors
cls_StepElement_Surface3dElementDescriptor.def(py::init<>());

// Methods
cls_StepElement_Surface3dElementDescriptor.def("Init", (void (StepElement_Surface3dElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> &, const StepElement_Element2dShape)) &StepElement_Surface3dElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aElementDescriptor_TopologyOrder"), py::arg("aElementDescriptor_Description"), py::arg("aPurpose"), py::arg("aShape"));
cls_StepElement_Surface3dElementDescriptor.def("Purpose", (opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::Purpose, "Returns field Purpose");
cls_StepElement_Surface3dElementDescriptor.def("SetPurpose", (void (StepElement_Surface3dElementDescriptor::*)(const opencascade::handle<StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember> &)) &StepElement_Surface3dElementDescriptor::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepElement_Surface3dElementDescriptor.def("Shape", (StepElement_Element2dShape (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::Shape, "Returns field Shape");
cls_StepElement_Surface3dElementDescriptor.def("SetShape", (void (StepElement_Surface3dElementDescriptor::*)(const StepElement_Element2dShape)) &StepElement_Surface3dElementDescriptor::SetShape, "Set field Shape", py::arg("Shape"));
cls_StepElement_Surface3dElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_Surface3dElementDescriptor::get_type_name, "None");
cls_StepElement_Surface3dElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_Surface3dElementDescriptor::get_type_descriptor, "None");
cls_StepElement_Surface3dElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_Surface3dElementDescriptor::*)() const) &StepElement_Surface3dElementDescriptor::DynamicType, "None");

// CLASS: STEPELEMENT_SURFACEELEMENTPROPERTY
py::class_<StepElement_SurfaceElementProperty, opencascade::handle<StepElement_SurfaceElementProperty>, Standard_Transient> cls_StepElement_SurfaceElementProperty(mod, "StepElement_SurfaceElementProperty", "Representation of STEP entity SurfaceElementProperty");

// Constructors
cls_StepElement_SurfaceElementProperty.def(py::init<>());

// Methods
cls_StepElement_SurfaceElementProperty.def("Init", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_SurfaceSectionField> &)) &StepElement_SurfaceElementProperty::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyId"), py::arg("aDescription"), py::arg("aSection"));
cls_StepElement_SurfaceElementProperty.def("PropertyId", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::PropertyId, "Returns field PropertyId");
cls_StepElement_SurfaceElementProperty.def("SetPropertyId", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementProperty::SetPropertyId, "Set field PropertyId", py::arg("PropertyId"));
cls_StepElement_SurfaceElementProperty.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::Description, "Returns field Description");
cls_StepElement_SurfaceElementProperty.def("SetDescription", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementProperty::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_SurfaceElementProperty.def("Section", (opencascade::handle<StepElement_SurfaceSectionField> (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::Section, "Returns field Section");
cls_StepElement_SurfaceElementProperty.def("SetSection", (void (StepElement_SurfaceElementProperty::*)(const opencascade::handle<StepElement_SurfaceSectionField> &)) &StepElement_SurfaceElementProperty::SetSection, "Set field Section", py::arg("Section"));
cls_StepElement_SurfaceElementProperty.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceElementProperty::get_type_name, "None");
cls_StepElement_SurfaceElementProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceElementProperty::get_type_descriptor, "None");
cls_StepElement_SurfaceElementProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceElementProperty::*)() const) &StepElement_SurfaceElementProperty::DynamicType, "None");

// CLASS: STEPELEMENT_SURFACESECTIONFIELD
py::class_<StepElement_SurfaceSectionField, opencascade::handle<StepElement_SurfaceSectionField>, Standard_Transient> cls_StepElement_SurfaceSectionField(mod, "StepElement_SurfaceSectionField", "Representation of STEP entity SurfaceSectionField");

// Constructors
cls_StepElement_SurfaceSectionField.def(py::init<>());

// Methods
cls_StepElement_SurfaceSectionField.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSectionField::get_type_name, "None");
cls_StepElement_SurfaceSectionField.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSectionField::get_type_descriptor, "None");
cls_StepElement_SurfaceSectionField.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSectionField::*)() const) &StepElement_SurfaceSectionField::DynamicType, "None");

// CLASS: STEPELEMENT_SURFACESECTIONFIELDCONSTANT
py::class_<StepElement_SurfaceSectionFieldConstant, opencascade::handle<StepElement_SurfaceSectionFieldConstant>, StepElement_SurfaceSectionField> cls_StepElement_SurfaceSectionFieldConstant(mod, "StepElement_SurfaceSectionFieldConstant", "Representation of STEP entity SurfaceSectionFieldConstant");

// Constructors
cls_StepElement_SurfaceSectionFieldConstant.def(py::init<>());

// Methods
cls_StepElement_SurfaceSectionFieldConstant.def("Init", (void (StepElement_SurfaceSectionFieldConstant::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepElement_SurfaceSectionFieldConstant::Init, "Initialize all fields (own and inherited)", py::arg("aDefinition"));
cls_StepElement_SurfaceSectionFieldConstant.def("Definition", (opencascade::handle<StepElement_SurfaceSection> (StepElement_SurfaceSectionFieldConstant::*)() const) &StepElement_SurfaceSectionFieldConstant::Definition, "Returns field Definition");
cls_StepElement_SurfaceSectionFieldConstant.def("SetDefinition", (void (StepElement_SurfaceSectionFieldConstant::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepElement_SurfaceSectionFieldConstant::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepElement_SurfaceSectionFieldConstant.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSectionFieldConstant::get_type_name, "None");
cls_StepElement_SurfaceSectionFieldConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSectionFieldConstant::get_type_descriptor, "None");
cls_StepElement_SurfaceSectionFieldConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSectionFieldConstant::*)() const) &StepElement_SurfaceSectionFieldConstant::DynamicType, "None");

// CLASS: STEPELEMENT_SURFACESECTIONFIELDVARYING
py::class_<StepElement_SurfaceSectionFieldVarying, opencascade::handle<StepElement_SurfaceSectionFieldVarying>, StepElement_SurfaceSectionField> cls_StepElement_SurfaceSectionFieldVarying(mod, "StepElement_SurfaceSectionFieldVarying", "Representation of STEP entity SurfaceSectionFieldVarying");

// Constructors
cls_StepElement_SurfaceSectionFieldVarying.def(py::init<>());

// Methods
cls_StepElement_SurfaceSectionFieldVarying.def("Init", (void (StepElement_SurfaceSectionFieldVarying::*)(const opencascade::handle<StepElement_HArray1OfSurfaceSection> &, const Standard_Boolean)) &StepElement_SurfaceSectionFieldVarying::Init, "Initialize all fields (own and inherited)", py::arg("aDefinitions"), py::arg("aAdditionalNodeValues"));
cls_StepElement_SurfaceSectionFieldVarying.def("Definitions", (opencascade::handle<StepElement_HArray1OfSurfaceSection> (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::Definitions, "Returns field Definitions");
cls_StepElement_SurfaceSectionFieldVarying.def("SetDefinitions", (void (StepElement_SurfaceSectionFieldVarying::*)(const opencascade::handle<StepElement_HArray1OfSurfaceSection> &)) &StepElement_SurfaceSectionFieldVarying::SetDefinitions, "Set field Definitions", py::arg("Definitions"));
cls_StepElement_SurfaceSectionFieldVarying.def("AdditionalNodeValues", (Standard_Boolean (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::AdditionalNodeValues, "Returns field AdditionalNodeValues");
cls_StepElement_SurfaceSectionFieldVarying.def("SetAdditionalNodeValues", (void (StepElement_SurfaceSectionFieldVarying::*)(const Standard_Boolean)) &StepElement_SurfaceSectionFieldVarying::SetAdditionalNodeValues, "Set field AdditionalNodeValues", py::arg("AdditionalNodeValues"));
cls_StepElement_SurfaceSectionFieldVarying.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSectionFieldVarying::get_type_name, "None");
cls_StepElement_SurfaceSectionFieldVarying.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSectionFieldVarying::get_type_descriptor, "None");
cls_StepElement_SurfaceSectionFieldVarying.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::DynamicType, "None");

// CLASS: STEPELEMENT_UNIFORMSURFACESECTION
py::class_<StepElement_UniformSurfaceSection, opencascade::handle<StepElement_UniformSurfaceSection>, StepElement_SurfaceSection> cls_StepElement_UniformSurfaceSection(mod, "StepElement_UniformSurfaceSection", "Representation of STEP entity UniformSurfaceSection");

// Constructors
cls_StepElement_UniformSurfaceSection.def(py::init<>());

// Methods
cls_StepElement_UniformSurfaceSection.def("Init", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &, const Standard_Real, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::Init, "Initialize all fields (own and inherited)", py::arg("aSurfaceSection_Offset"), py::arg("aSurfaceSection_NonStructuralMass"), py::arg("aSurfaceSection_NonStructuralMassOffset"), py::arg("aThickness"), py::arg("aBendingThickness"), py::arg("aShearThickness"));
cls_StepElement_UniformSurfaceSection.def("Thickness", (Standard_Real (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::Thickness, "Returns field Thickness");
cls_StepElement_UniformSurfaceSection.def("SetThickness", (void (StepElement_UniformSurfaceSection::*)(const Standard_Real)) &StepElement_UniformSurfaceSection::SetThickness, "Set field Thickness", py::arg("Thickness"));
cls_StepElement_UniformSurfaceSection.def("BendingThickness", (StepElement_MeasureOrUnspecifiedValue (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::BendingThickness, "Returns field BendingThickness");
cls_StepElement_UniformSurfaceSection.def("SetBendingThickness", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::SetBendingThickness, "Set field BendingThickness", py::arg("BendingThickness"));
cls_StepElement_UniformSurfaceSection.def("ShearThickness", (StepElement_MeasureOrUnspecifiedValue (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::ShearThickness, "Returns field ShearThickness");
cls_StepElement_UniformSurfaceSection.def("SetShearThickness", (void (StepElement_UniformSurfaceSection::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_UniformSurfaceSection::SetShearThickness, "Set field ShearThickness", py::arg("ShearThickness"));
cls_StepElement_UniformSurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_UniformSurfaceSection::get_type_name, "None");
cls_StepElement_UniformSurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_UniformSurfaceSection::get_type_descriptor, "None");
cls_StepElement_UniformSurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_UniformSurfaceSection::*)() const) &StepElement_UniformSurfaceSection::DynamicType, "None");

// CLASS: STEPELEMENT_VOLUME3DELEMENTDESCRIPTOR
py::class_<StepElement_Volume3dElementDescriptor, opencascade::handle<StepElement_Volume3dElementDescriptor>, StepElement_ElementDescriptor> cls_StepElement_Volume3dElementDescriptor(mod, "StepElement_Volume3dElementDescriptor", "Representation of STEP entity Volume3dElementDescriptor");

// Constructors
cls_StepElement_Volume3dElementDescriptor.def(py::init<>());

// Methods
cls_StepElement_Volume3dElementDescriptor.def("Init", (void (StepElement_Volume3dElementDescriptor::*)(const StepElement_ElementOrder, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepElement_HArray1OfVolumeElementPurposeMember> &, const StepElement_Volume3dElementShape)) &StepElement_Volume3dElementDescriptor::Init, "Initialize all fields (own and inherited)", py::arg("aElementDescriptor_TopologyOrder"), py::arg("aElementDescriptor_Description"), py::arg("aPurpose"), py::arg("aShape"));
cls_StepElement_Volume3dElementDescriptor.def("Purpose", (opencascade::handle<StepElement_HArray1OfVolumeElementPurposeMember> (StepElement_Volume3dElementDescriptor::*)() const) &StepElement_Volume3dElementDescriptor::Purpose, "Returns field Purpose");
cls_StepElement_Volume3dElementDescriptor.def("SetPurpose", (void (StepElement_Volume3dElementDescriptor::*)(const opencascade::handle<StepElement_HArray1OfVolumeElementPurposeMember> &)) &StepElement_Volume3dElementDescriptor::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepElement_Volume3dElementDescriptor.def("Shape", (StepElement_Volume3dElementShape (StepElement_Volume3dElementDescriptor::*)() const) &StepElement_Volume3dElementDescriptor::Shape, "Returns field Shape");
cls_StepElement_Volume3dElementDescriptor.def("SetShape", (void (StepElement_Volume3dElementDescriptor::*)(const StepElement_Volume3dElementShape)) &StepElement_Volume3dElementDescriptor::SetShape, "Set field Shape", py::arg("Shape"));
cls_StepElement_Volume3dElementDescriptor.def_static("get_type_name_", (const char * (*)()) &StepElement_Volume3dElementDescriptor::get_type_name, "None");
cls_StepElement_Volume3dElementDescriptor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_Volume3dElementDescriptor::get_type_descriptor, "None");
cls_StepElement_Volume3dElementDescriptor.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_Volume3dElementDescriptor::*)() const) &StepElement_Volume3dElementDescriptor::DynamicType, "None");


}
