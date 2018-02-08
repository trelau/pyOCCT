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

#include <StepShape_ShapeRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <StepShape_AdvancedBrepShapeRepresentation.hxx>
#include <StepShape_FaceSurface.hxx>
#include <StepShape_AdvancedFace.hxx>
#include <StepShape_DimensionalLocation.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepShape_AngleRelator.hxx>
#include <StepShape_AngularLocation.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepShape_AngularSize.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepShape_Block.hxx>
#include <StepShape_BooleanOperator.hxx>
#include <StepShape_BooleanOperand.hxx>
#include <StepShape_BooleanResult.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepShape_BoxDomain.hxx>
#include <StepShape_HalfSpaceSolid.hxx>
#include <StepGeom_Surface.hxx>
#include <StepShape_BoxedHalfSpace.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_HArray1OfOrientedClosedShell.hxx>
#include <StepShape_OrientedClosedShell.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepShape_CompoundShapeRepresentation.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepShape_HArray1OfEdge.hxx>
#include <StepShape_ConnectedEdgeSet.hxx>
#include <StepShape_HArray1OfFace.hxx>
#include <StepShape_Face.hxx>
#include <StepRepr_Representation.hxx>
#include <StepShape_ConnectedFaceShapeRepresentation.hxx>
#include <StepShape_ConnectedFaceSubSet.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <StepShape_CsgShapeRepresentation.hxx>
#include <StepShape_SolidModel.hxx>
#include <StepShape_CsgSelect.hxx>
#include <StepShape_CsgSolid.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <StepShape_DefinitionalRepresentationAndShapeRepresentation.hxx>
#include <StepShape_DimensionalCharacteristic.hxx>
#include <StepShape_ShapeDimensionRepresentation.hxx>
#include <StepShape_DimensionalCharacteristicRepresentation.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepShape_DimensionalLocationWithPath.hxx>
#include <StepShape_DimensionalSizeWithPath.hxx>
#include <StepShape_Vertex.hxx>
#include <StepShape_Edge.hxx>
#include <StepShape_HArray1OfConnectedEdgeSet.hxx>
#include <StepShape_EdgeBasedWireframeModel.hxx>
#include <StepShape_EdgeBasedWireframeShapeRepresentation.hxx>
#include <StepGeom_Curve.hxx>
#include <StepShape_EdgeCurve.hxx>
#include <StepShape_Loop.hxx>
#include <StepShape_HArray1OfOrientedEdge.hxx>
#include <StepShape_OrientedEdge.hxx>
#include <StepShape_EdgeLoop.hxx>
#include <StepShape_SweptAreaSolid.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <StepGeom_Direction.hxx>
#include <StepShape_ExtrudedAreaSolid.hxx>
#include <StepShape_SweptFaceSolid.hxx>
#include <StepShape_ExtrudedFaceSolid.hxx>
#include <StepShape_HArray1OfFaceBound.hxx>
#include <StepShape_FaceBound.hxx>
#include <StepShape_HArray1OfConnectedFaceSet.hxx>
#include <StepShape_FaceBasedSurfaceModel.hxx>
#include <StepShape_FaceOuterBound.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <StepShape_FacetedBrepShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedSurfaceShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedWireframeShapeRepresentation.hxx>
#include <StepShape_GeometricSet.hxx>
#include <StepShape_GeometricCurveSet.hxx>
#include <StepShape_HArray1OfGeometricSetSelect.hxx>
#include <StepShape_GeometricSetSelect.hxx>
#include <StepShape_LimitsAndFits.hxx>
#include <StepShape_Path.hxx>
#include <StepShape_LoopAndPath.hxx>
#include <StepShape_ManifoldSurfaceShapeRepresentation.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepShape_HArray1OfValueQualifier.hxx>
#include <StepShape_ValueQualifier.hxx>
#include <StepShape_MeasureQualification.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.hxx>
#include <StepShape_NonManifoldSurfaceShapeRepresentation.hxx>
#include <StepShape_OpenShell.hxx>
#include <StepShape_OrientedFace.hxx>
#include <StepShape_OrientedOpenShell.hxx>
#include <StepShape_OrientedPath.hxx>
#include <StepShape_ToleranceMethodDefinition.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <StepShape_PointRepresentation.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepShape_PolyLoop.hxx>
#include <StepShape_PrecisionQualifier.hxx>
#include <StepShape_QualifiedRepresentationItem.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <StepShape_RevolvedAreaSolid.hxx>
#include <StepShape_RevolvedFaceSolid.hxx>
#include <StepShape_RightAngularWedge.hxx>
#include <StepShape_RightCircularCone.hxx>
#include <StepShape_RightCircularCylinder.hxx>
#include <StepGeom_Pcurve.hxx>
#include <StepShape_SeamEdge.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepShape_HArray1OfShapeDimensionRepresentationItem.hxx>
#include <StepShape_ShapeRepresentationWithParameters.hxx>
#include <StepShape_HArray1OfShell.hxx>
#include <StepShape_Shell.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <StepShape_SolidReplica.hxx>
#include <StepGeom_Point.hxx>
#include <StepShape_Sphere.hxx>
#include <StepShape_Subedge.hxx>
#include <StepShape_Subface.hxx>
#include <StepShape_ToleranceValue.hxx>
#include <StepShape_Torus.hxx>
#include <StepShape_TransitionalShapeRepresentation.hxx>
#include <StepShape_TypeQualifier.hxx>
#include <StepShape_ValueFormatTypeQualifier.hxx>
#include <StepShape_VertexLoop.hxx>
#include <StepShape_VertexPoint.hxx>
#include <NCollection_Array1.hxx>
#include <StepShape_Array1OfFaceBound.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepShape_Array1OfEdge.hxx>
#include <StepShape_Array1OfConnectedEdgeSet.hxx>
#include <StepShape_Array1OfFace.hxx>
#include <StepShape_Array1OfConnectedFaceSet.hxx>
#include <StepData_SelectType.hxx>
#include <StepShape_Array1OfGeometricSetSelect.hxx>
#include <StepShape_Array1OfOrientedClosedShell.hxx>
#include <StepShape_Array1OfOrientedEdge.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepGeom_Placement.hxx>
#include <StepShape_ShapeDimensionRepresentationItem.hxx>
#include <StepShape_Array1OfShapeDimensionRepresentationItem.hxx>
#include <StepShape_Array1OfShell.hxx>
#include <StepShape_Array1OfValueQualifier.hxx>
#include <StepShape_CsgPrimitive.hxx>
#include <StepShape_DirectedDimensionalLocation.hxx>
#include <StepShape_ReversibleTopologyItem.hxx>
#include <StepShape_SurfaceModel.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(StepShape, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.StepGeom");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.StepData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_AngleRelator.hxx
	py::enum_<StepShape_AngleRelator>(mod, "StepShape_AngleRelator", "None")
		.value("StepShape_Equal", StepShape_AngleRelator::StepShape_Equal)
		.value("StepShape_Large", StepShape_AngleRelator::StepShape_Large)
		.value("StepShape_Small", StepShape_AngleRelator::StepShape_Small)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BooleanOperator.hxx
	py::enum_<StepShape_BooleanOperator>(mod, "StepShape_BooleanOperator", "None")
		.value("StepShape_boDifference", StepShape_BooleanOperator::StepShape_boDifference)
		.value("StepShape_boIntersection", StepShape_BooleanOperator::StepShape_boIntersection)
		.value("StepShape_boUnion", StepShape_BooleanOperator::StepShape_boUnion)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShapeRepresentation.hxx
	py::class_<StepShape_ShapeRepresentation, opencascade::handle<StepShape_ShapeRepresentation>, StepRepr_Representation> cls_StepShape_ShapeRepresentation(mod, "StepShape_ShapeRepresentation", "None");
	cls_StepShape_ShapeRepresentation.def(py::init<>());
	cls_StepShape_ShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ShapeRepresentation::get_type_name, "None");
	cls_StepShape_ShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_ShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShapeRepresentation::*)() const ) &StepShape_ShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_TopologicalRepresentationItem.hxx
	py::class_<StepShape_TopologicalRepresentationItem, opencascade::handle<StepShape_TopologicalRepresentationItem>, StepRepr_RepresentationItem> cls_StepShape_TopologicalRepresentationItem(mod, "StepShape_TopologicalRepresentationItem", "None");
	cls_StepShape_TopologicalRepresentationItem.def(py::init<>());
	cls_StepShape_TopologicalRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_TopologicalRepresentationItem::get_type_name, "None");
	cls_StepShape_TopologicalRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_TopologicalRepresentationItem::get_type_descriptor, "None");
	cls_StepShape_TopologicalRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_TopologicalRepresentationItem::*)() const ) &StepShape_TopologicalRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalLocation.hxx
	py::class_<StepShape_DimensionalLocation, opencascade::handle<StepShape_DimensionalLocation>, StepRepr_ShapeAspectRelationship> cls_StepShape_DimensionalLocation(mod, "StepShape_DimensionalLocation", "Representation of STEP entity DimensionalLocation");
	cls_StepShape_DimensionalLocation.def(py::init<>());
	cls_StepShape_DimensionalLocation.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalLocation::get_type_name, "None");
	cls_StepShape_DimensionalLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalLocation::get_type_descriptor, "None");
	cls_StepShape_DimensionalLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalLocation::*)() const ) &StepShape_DimensionalLocation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalSize.hxx
	py::class_<StepShape_DimensionalSize, opencascade::handle<StepShape_DimensionalSize>, Standard_Transient> cls_StepShape_DimensionalSize(mod, "StepShape_DimensionalSize", "Representation of STEP entity DimensionalSize");
	cls_StepShape_DimensionalSize.def(py::init<>());
	cls_StepShape_DimensionalSize.def("Init", (void (StepShape_DimensionalSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_DimensionalSize::Init, "Initialize all fields (own and inherited)", py::arg("aAppliesTo"), py::arg("aName"));
	cls_StepShape_DimensionalSize.def("AppliesTo", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalSize::*)() const ) &StepShape_DimensionalSize::AppliesTo, "Returns field AppliesTo");
	cls_StepShape_DimensionalSize.def("SetAppliesTo", (void (StepShape_DimensionalSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSize::SetAppliesTo, "Set field AppliesTo", py::arg("AppliesTo"));
	cls_StepShape_DimensionalSize.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_DimensionalSize::*)() const ) &StepShape_DimensionalSize::Name, "Returns field Name");
	cls_StepShape_DimensionalSize.def("SetName", (void (StepShape_DimensionalSize::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_DimensionalSize::SetName, "Set field Name", py::arg("Name"));
	cls_StepShape_DimensionalSize.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalSize::get_type_name, "None");
	cls_StepShape_DimensionalSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalSize::get_type_descriptor, "None");
	cls_StepShape_DimensionalSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalSize::*)() const ) &StepShape_DimensionalSize::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Block.hxx
	py::class_<StepShape_Block, opencascade::handle<StepShape_Block>, StepGeom_GeometricRepresentationItem> cls_StepShape_Block(mod, "StepShape_Block", "None");
	cls_StepShape_Block.def(py::init<>());
	cls_StepShape_Block.def("Init", (void (StepShape_Block::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_Block::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aX"), py::arg("aY"), py::arg("aZ"));
	cls_StepShape_Block.def("SetPosition", (void (StepShape_Block::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepShape_Block::SetPosition, "None", py::arg("aPosition"));
	cls_StepShape_Block.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepShape_Block::*)() const ) &StepShape_Block::Position, "None");
	cls_StepShape_Block.def("SetX", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetX, "None", py::arg("aX"));
	cls_StepShape_Block.def("X", (Standard_Real (StepShape_Block::*)() const ) &StepShape_Block::X, "None");
	cls_StepShape_Block.def("SetY", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetY, "None", py::arg("aY"));
	cls_StepShape_Block.def("Y", (Standard_Real (StepShape_Block::*)() const ) &StepShape_Block::Y, "None");
	cls_StepShape_Block.def("SetZ", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetZ, "None", py::arg("aZ"));
	cls_StepShape_Block.def("Z", (Standard_Real (StepShape_Block::*)() const ) &StepShape_Block::Z, "None");
	cls_StepShape_Block.def_static("get_type_name_", (const char * (*)()) &StepShape_Block::get_type_name, "None");
	cls_StepShape_Block.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Block::get_type_descriptor, "None");
	cls_StepShape_Block.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Block::*)() const ) &StepShape_Block::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BooleanResult.hxx
	py::class_<StepShape_BooleanResult, opencascade::handle<StepShape_BooleanResult>, StepGeom_GeometricRepresentationItem> cls_StepShape_BooleanResult(mod, "StepShape_BooleanResult", "None");
	cls_StepShape_BooleanResult.def(py::init<>());
	cls_StepShape_BooleanResult.def("Init", (void (StepShape_BooleanResult::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepShape_BooleanOperator, const StepShape_BooleanOperand &, const StepShape_BooleanOperand &)) &StepShape_BooleanResult::Init, "None", py::arg("aName"), py::arg("aOperator"), py::arg("aFirstOperand"), py::arg("aSecondOperand"));
	cls_StepShape_BooleanResult.def("SetOperator", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperator)) &StepShape_BooleanResult::SetOperator, "None", py::arg("aOperator"));
	cls_StepShape_BooleanResult.def("Operator", (StepShape_BooleanOperator (StepShape_BooleanResult::*)() const ) &StepShape_BooleanResult::Operator, "None");
	cls_StepShape_BooleanResult.def("SetFirstOperand", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperand &)) &StepShape_BooleanResult::SetFirstOperand, "None", py::arg("aFirstOperand"));
	cls_StepShape_BooleanResult.def("FirstOperand", (StepShape_BooleanOperand (StepShape_BooleanResult::*)() const ) &StepShape_BooleanResult::FirstOperand, "None");
	cls_StepShape_BooleanResult.def("SetSecondOperand", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperand &)) &StepShape_BooleanResult::SetSecondOperand, "None", py::arg("aSecondOperand"));
	cls_StepShape_BooleanResult.def("SecondOperand", (StepShape_BooleanOperand (StepShape_BooleanResult::*)() const ) &StepShape_BooleanResult::SecondOperand, "None");
	cls_StepShape_BooleanResult.def_static("get_type_name_", (const char * (*)()) &StepShape_BooleanResult::get_type_name, "None");
	cls_StepShape_BooleanResult.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BooleanResult::get_type_descriptor, "None");
	cls_StepShape_BooleanResult.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BooleanResult::*)() const ) &StepShape_BooleanResult::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BoxDomain.hxx
	py::class_<StepShape_BoxDomain, opencascade::handle<StepShape_BoxDomain>, Standard_Transient> cls_StepShape_BoxDomain(mod, "StepShape_BoxDomain", "None");
	cls_StepShape_BoxDomain.def(py::init<>());
	cls_StepShape_BoxDomain.def("Init", (void (StepShape_BoxDomain::*)(const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_BoxDomain::Init, "None", py::arg("aCorner"), py::arg("aXlength"), py::arg("aYlength"), py::arg("aZlength"));
	cls_StepShape_BoxDomain.def("SetCorner", (void (StepShape_BoxDomain::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepShape_BoxDomain::SetCorner, "None", py::arg("aCorner"));
	cls_StepShape_BoxDomain.def("Corner", (opencascade::handle<StepGeom_CartesianPoint> (StepShape_BoxDomain::*)() const ) &StepShape_BoxDomain::Corner, "None");
	cls_StepShape_BoxDomain.def("SetXlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetXlength, "None", py::arg("aXlength"));
	cls_StepShape_BoxDomain.def("Xlength", (Standard_Real (StepShape_BoxDomain::*)() const ) &StepShape_BoxDomain::Xlength, "None");
	cls_StepShape_BoxDomain.def("SetYlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetYlength, "None", py::arg("aYlength"));
	cls_StepShape_BoxDomain.def("Ylength", (Standard_Real (StepShape_BoxDomain::*)() const ) &StepShape_BoxDomain::Ylength, "None");
	cls_StepShape_BoxDomain.def("SetZlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetZlength, "None", py::arg("aZlength"));
	cls_StepShape_BoxDomain.def("Zlength", (Standard_Real (StepShape_BoxDomain::*)() const ) &StepShape_BoxDomain::Zlength, "None");
	cls_StepShape_BoxDomain.def_static("get_type_name_", (const char * (*)()) &StepShape_BoxDomain::get_type_name, "None");
	cls_StepShape_BoxDomain.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BoxDomain::get_type_descriptor, "None");
	cls_StepShape_BoxDomain.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BoxDomain::*)() const ) &StepShape_BoxDomain::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HalfSpaceSolid.hxx
	py::class_<StepShape_HalfSpaceSolid, opencascade::handle<StepShape_HalfSpaceSolid>, StepGeom_GeometricRepresentationItem> cls_StepShape_HalfSpaceSolid(mod, "StepShape_HalfSpaceSolid", "None");
	cls_StepShape_HalfSpaceSolid.def(py::init<>());
	cls_StepShape_HalfSpaceSolid.def("Init", (void (StepShape_HalfSpaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean)) &StepShape_HalfSpaceSolid::Init, "None", py::arg("aName"), py::arg("aBaseSurface"), py::arg("aAgreementFlag"));
	cls_StepShape_HalfSpaceSolid.def("SetBaseSurface", (void (StepShape_HalfSpaceSolid::*)(const opencascade::handle<StepGeom_Surface> &)) &StepShape_HalfSpaceSolid::SetBaseSurface, "None", py::arg("aBaseSurface"));
	cls_StepShape_HalfSpaceSolid.def("BaseSurface", (opencascade::handle<StepGeom_Surface> (StepShape_HalfSpaceSolid::*)() const ) &StepShape_HalfSpaceSolid::BaseSurface, "None");
	cls_StepShape_HalfSpaceSolid.def("SetAgreementFlag", (void (StepShape_HalfSpaceSolid::*)(const Standard_Boolean)) &StepShape_HalfSpaceSolid::SetAgreementFlag, "None", py::arg("aAgreementFlag"));
	cls_StepShape_HalfSpaceSolid.def("AgreementFlag", (Standard_Boolean (StepShape_HalfSpaceSolid::*)() const ) &StepShape_HalfSpaceSolid::AgreementFlag, "None");
	cls_StepShape_HalfSpaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_HalfSpaceSolid::get_type_name, "None");
	cls_StepShape_HalfSpaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HalfSpaceSolid::get_type_descriptor, "None");
	cls_StepShape_HalfSpaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HalfSpaceSolid::*)() const ) &StepShape_HalfSpaceSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SolidModel.hxx
	py::class_<StepShape_SolidModel, opencascade::handle<StepShape_SolidModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_SolidModel(mod, "StepShape_SolidModel", "None");
	cls_StepShape_SolidModel.def(py::init<>());
	cls_StepShape_SolidModel.def_static("get_type_name_", (const char * (*)()) &StepShape_SolidModel::get_type_name, "None");
	cls_StepShape_SolidModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SolidModel::get_type_descriptor, "None");
	cls_StepShape_SolidModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SolidModel::*)() const ) &StepShape_SolidModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ConnectedFaceSet.hxx
	py::class_<StepShape_ConnectedFaceSet, opencascade::handle<StepShape_ConnectedFaceSet>, StepShape_TopologicalRepresentationItem> cls_StepShape_ConnectedFaceSet(mod, "StepShape_ConnectedFaceSet", "None");
	cls_StepShape_ConnectedFaceSet.def(py::init<>());
	cls_StepShape_ConnectedFaceSet.def("Init", (void (StepShape_ConnectedFaceSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_ConnectedFaceSet::Init, "None", py::arg("aName"), py::arg("aCfsFaces"));
	cls_StepShape_ConnectedFaceSet.def("SetCfsFaces", (void (StepShape_ConnectedFaceSet::*)(const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_ConnectedFaceSet::SetCfsFaces, "None", py::arg("aCfsFaces"));
	cls_StepShape_ConnectedFaceSet.def("CfsFaces", (opencascade::handle<StepShape_HArray1OfFace> (StepShape_ConnectedFaceSet::*)() const ) &StepShape_ConnectedFaceSet::CfsFaces, "None");
	cls_StepShape_ConnectedFaceSet.def("CfsFacesValue", (opencascade::handle<StepShape_Face> (StepShape_ConnectedFaceSet::*)(const Standard_Integer) const ) &StepShape_ConnectedFaceSet::CfsFacesValue, "None", py::arg("num"));
	cls_StepShape_ConnectedFaceSet.def("NbCfsFaces", (Standard_Integer (StepShape_ConnectedFaceSet::*)() const ) &StepShape_ConnectedFaceSet::NbCfsFaces, "None");
	cls_StepShape_ConnectedFaceSet.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedFaceSet::get_type_name, "None");
	cls_StepShape_ConnectedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedFaceSet::get_type_descriptor, "None");
	cls_StepShape_ConnectedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedFaceSet::*)() const ) &StepShape_ConnectedFaceSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_CompoundShapeRepresentation.hxx
	py::class_<StepShape_CompoundShapeRepresentation, opencascade::handle<StepShape_CompoundShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_CompoundShapeRepresentation(mod, "StepShape_CompoundShapeRepresentation", "Representation of STEP entity CompoundShapeRepresentation");
	cls_StepShape_CompoundShapeRepresentation.def(py::init<>());
	cls_StepShape_CompoundShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_CompoundShapeRepresentation::get_type_name, "None");
	cls_StepShape_CompoundShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_CompoundShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_CompoundShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_CompoundShapeRepresentation::*)() const ) &StepShape_CompoundShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ConnectedEdgeSet.hxx
	py::class_<StepShape_ConnectedEdgeSet, opencascade::handle<StepShape_ConnectedEdgeSet>, StepShape_TopologicalRepresentationItem> cls_StepShape_ConnectedEdgeSet(mod, "StepShape_ConnectedEdgeSet", "Representation of STEP entity ConnectedEdgeSet");
	cls_StepShape_ConnectedEdgeSet.def(py::init<>());
	cls_StepShape_ConnectedEdgeSet.def("Init", (void (StepShape_ConnectedEdgeSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfEdge> &)) &StepShape_ConnectedEdgeSet::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCesEdges"));
	cls_StepShape_ConnectedEdgeSet.def("CesEdges", (opencascade::handle<StepShape_HArray1OfEdge> (StepShape_ConnectedEdgeSet::*)() const ) &StepShape_ConnectedEdgeSet::CesEdges, "Returns field CesEdges");
	cls_StepShape_ConnectedEdgeSet.def("SetCesEdges", (void (StepShape_ConnectedEdgeSet::*)(const opencascade::handle<StepShape_HArray1OfEdge> &)) &StepShape_ConnectedEdgeSet::SetCesEdges, "Set field CesEdges", py::arg("CesEdges"));
	cls_StepShape_ConnectedEdgeSet.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedEdgeSet::get_type_name, "None");
	cls_StepShape_ConnectedEdgeSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedEdgeSet::get_type_descriptor, "None");
	cls_StepShape_ConnectedEdgeSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedEdgeSet::*)() const ) &StepShape_ConnectedEdgeSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ClosedShell.hxx
	py::class_<StepShape_ClosedShell, opencascade::handle<StepShape_ClosedShell>, StepShape_ConnectedFaceSet> cls_StepShape_ClosedShell(mod, "StepShape_ClosedShell", "None");
	cls_StepShape_ClosedShell.def(py::init<>());
	cls_StepShape_ClosedShell.def_static("get_type_name_", (const char * (*)()) &StepShape_ClosedShell::get_type_name, "None");
	cls_StepShape_ClosedShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ClosedShell::get_type_descriptor, "None");
	cls_StepShape_ClosedShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ClosedShell::*)() const ) &StepShape_ClosedShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ConnectedFaceShapeRepresentation.hxx
	py::class_<StepShape_ConnectedFaceShapeRepresentation, opencascade::handle<StepShape_ConnectedFaceShapeRepresentation>, StepRepr_Representation> cls_StepShape_ConnectedFaceShapeRepresentation(mod, "StepShape_ConnectedFaceShapeRepresentation", "Representation of STEP entity ConnectedFaceShapeRepresentation");
	cls_StepShape_ConnectedFaceShapeRepresentation.def(py::init<>());
	cls_StepShape_ConnectedFaceShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedFaceShapeRepresentation::get_type_name, "None");
	cls_StepShape_ConnectedFaceShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedFaceShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_ConnectedFaceShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedFaceShapeRepresentation::*)() const ) &StepShape_ConnectedFaceShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ConnectedFaceSubSet.hxx
	py::class_<StepShape_ConnectedFaceSubSet, opencascade::handle<StepShape_ConnectedFaceSubSet>, StepShape_ConnectedFaceSet> cls_StepShape_ConnectedFaceSubSet(mod, "StepShape_ConnectedFaceSubSet", "Representation of STEP entity ConnectedFaceSubSet");
	cls_StepShape_ConnectedFaceSubSet.def(py::init<>());
	cls_StepShape_ConnectedFaceSubSet.def("Init", (void (StepShape_ConnectedFaceSubSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFace> &, const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ConnectedFaceSubSet::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aConnectedFaceSet_CfsFaces"), py::arg("aParentFaceSet"));
	cls_StepShape_ConnectedFaceSubSet.def("ParentFaceSet", (opencascade::handle<StepShape_ConnectedFaceSet> (StepShape_ConnectedFaceSubSet::*)() const ) &StepShape_ConnectedFaceSubSet::ParentFaceSet, "Returns field ParentFaceSet");
	cls_StepShape_ConnectedFaceSubSet.def("SetParentFaceSet", (void (StepShape_ConnectedFaceSubSet::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ConnectedFaceSubSet::SetParentFaceSet, "Set field ParentFaceSet", py::arg("ParentFaceSet"));
	cls_StepShape_ConnectedFaceSubSet.def_static("get_type_name_", (const char * (*)()) &StepShape_ConnectedFaceSubSet::get_type_name, "None");
	cls_StepShape_ConnectedFaceSubSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ConnectedFaceSubSet::get_type_descriptor, "None");
	cls_StepShape_ConnectedFaceSubSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ConnectedFaceSubSet::*)() const ) &StepShape_ConnectedFaceSubSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ContextDependentShapeRepresentation.hxx
	py::class_<StepShape_ContextDependentShapeRepresentation, opencascade::handle<StepShape_ContextDependentShapeRepresentation>, Standard_Transient> cls_StepShape_ContextDependentShapeRepresentation(mod, "StepShape_ContextDependentShapeRepresentation", "None");
	cls_StepShape_ContextDependentShapeRepresentation.def(py::init<>());
	cls_StepShape_ContextDependentShapeRepresentation.def("Init", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationship> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepShape_ContextDependentShapeRepresentation::Init, "None", py::arg("aRepRel"), py::arg("aProRel"));
	cls_StepShape_ContextDependentShapeRepresentation.def("RepresentationRelation", (opencascade::handle<StepRepr_ShapeRepresentationRelationship> (StepShape_ContextDependentShapeRepresentation::*)() const ) &StepShape_ContextDependentShapeRepresentation::RepresentationRelation, "None");
	cls_StepShape_ContextDependentShapeRepresentation.def("SetRepresentationRelation", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationship> &)) &StepShape_ContextDependentShapeRepresentation::SetRepresentationRelation, "None", py::arg("aRepRel"));
	cls_StepShape_ContextDependentShapeRepresentation.def("RepresentedProductRelation", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepShape_ContextDependentShapeRepresentation::*)() const ) &StepShape_ContextDependentShapeRepresentation::RepresentedProductRelation, "None");
	cls_StepShape_ContextDependentShapeRepresentation.def("SetRepresentedProductRelation", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepShape_ContextDependentShapeRepresentation::SetRepresentedProductRelation, "None", py::arg("aProRel"));
	cls_StepShape_ContextDependentShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ContextDependentShapeRepresentation::get_type_name, "None");
	cls_StepShape_ContextDependentShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ContextDependentShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_ContextDependentShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ContextDependentShapeRepresentation::*)() const ) &StepShape_ContextDependentShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_CsgShapeRepresentation.hxx
	py::class_<StepShape_CsgShapeRepresentation, opencascade::handle<StepShape_CsgShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_CsgShapeRepresentation(mod, "StepShape_CsgShapeRepresentation", "None");
	cls_StepShape_CsgShapeRepresentation.def(py::init<>());
	cls_StepShape_CsgShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_CsgShapeRepresentation::get_type_name, "None");
	cls_StepShape_CsgShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_CsgShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_CsgShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_CsgShapeRepresentation::*)() const ) &StepShape_CsgShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_CsgSolid.hxx
	py::class_<StepShape_CsgSolid, opencascade::handle<StepShape_CsgSolid>, StepShape_SolidModel> cls_StepShape_CsgSolid(mod, "StepShape_CsgSolid", "None");
	cls_StepShape_CsgSolid.def(py::init<>());
	cls_StepShape_CsgSolid.def("Init", (void (StepShape_CsgSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepShape_CsgSelect &)) &StepShape_CsgSolid::Init, "None", py::arg("aName"), py::arg("aTreeRootExpression"));
	cls_StepShape_CsgSolid.def("SetTreeRootExpression", (void (StepShape_CsgSolid::*)(const StepShape_CsgSelect &)) &StepShape_CsgSolid::SetTreeRootExpression, "None", py::arg("aTreeRootExpression"));
	cls_StepShape_CsgSolid.def("TreeRootExpression", (StepShape_CsgSelect (StepShape_CsgSolid::*)() const ) &StepShape_CsgSolid::TreeRootExpression, "None");
	cls_StepShape_CsgSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_CsgSolid::get_type_name, "None");
	cls_StepShape_CsgSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_CsgSolid::get_type_descriptor, "None");
	cls_StepShape_CsgSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_CsgSolid::*)() const ) &StepShape_CsgSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DefinitionalRepresentationAndShapeRepresentation.hxx
	py::class_<StepShape_DefinitionalRepresentationAndShapeRepresentation, opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation>, StepRepr_DefinitionalRepresentation> cls_StepShape_DefinitionalRepresentationAndShapeRepresentation(mod, "StepShape_DefinitionalRepresentationAndShapeRepresentation", "Implements complex type (DEFINITIONAL_REPRESENTATION,REPRESENTATION,SHAPE_REPRESENTATION)");
	cls_StepShape_DefinitionalRepresentationAndShapeRepresentation.def(py::init<>());
	cls_StepShape_DefinitionalRepresentationAndShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_DefinitionalRepresentationAndShapeRepresentation::get_type_name, "None");
	cls_StepShape_DefinitionalRepresentationAndShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DefinitionalRepresentationAndShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_DefinitionalRepresentationAndShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DefinitionalRepresentationAndShapeRepresentation::*)() const ) &StepShape_DefinitionalRepresentationAndShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalCharacteristicRepresentation.hxx
	py::class_<StepShape_DimensionalCharacteristicRepresentation, opencascade::handle<StepShape_DimensionalCharacteristicRepresentation>, Standard_Transient> cls_StepShape_DimensionalCharacteristicRepresentation(mod, "StepShape_DimensionalCharacteristicRepresentation", "Representation of STEP entity DimensionalCharacteristicRepresentation");
	cls_StepShape_DimensionalCharacteristicRepresentation.def(py::init<>());
	cls_StepShape_DimensionalCharacteristicRepresentation.def("Init", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const StepShape_DimensionalCharacteristic &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &)) &StepShape_DimensionalCharacteristicRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aDimension"), py::arg("aRepresentation"));
	cls_StepShape_DimensionalCharacteristicRepresentation.def("Dimension", (StepShape_DimensionalCharacteristic (StepShape_DimensionalCharacteristicRepresentation::*)() const ) &StepShape_DimensionalCharacteristicRepresentation::Dimension, "Returns field Dimension");
	cls_StepShape_DimensionalCharacteristicRepresentation.def("SetDimension", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const StepShape_DimensionalCharacteristic &)) &StepShape_DimensionalCharacteristicRepresentation::SetDimension, "Set field Dimension", py::arg("Dimension"));
	cls_StepShape_DimensionalCharacteristicRepresentation.def("Representation", (opencascade::handle<StepShape_ShapeDimensionRepresentation> (StepShape_DimensionalCharacteristicRepresentation::*)() const ) &StepShape_DimensionalCharacteristicRepresentation::Representation, "Returns field Representation");
	cls_StepShape_DimensionalCharacteristicRepresentation.def("SetRepresentation", (void (StepShape_DimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepShape_ShapeDimensionRepresentation> &)) &StepShape_DimensionalCharacteristicRepresentation::SetRepresentation, "Set field Representation", py::arg("Representation"));
	cls_StepShape_DimensionalCharacteristicRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalCharacteristicRepresentation::get_type_name, "None");
	cls_StepShape_DimensionalCharacteristicRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalCharacteristicRepresentation::get_type_descriptor, "None");
	cls_StepShape_DimensionalCharacteristicRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalCharacteristicRepresentation::*)() const ) &StepShape_DimensionalCharacteristicRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_AngularLocation.hxx
	py::class_<StepShape_AngularLocation, opencascade::handle<StepShape_AngularLocation>, StepShape_DimensionalLocation> cls_StepShape_AngularLocation(mod, "StepShape_AngularLocation", "Representation of STEP entity AngularLocation");
	cls_StepShape_AngularLocation.def(py::init<>());
	cls_StepShape_AngularLocation.def("Init", (void (StepShape_AngularLocation::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const StepShape_AngleRelator)) &StepShape_AngularLocation::Init, "Initialize all fields (own and inherited)", py::arg("aShapeAspectRelationship_Name"), py::arg("hasShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_RelatingShapeAspect"), py::arg("aShapeAspectRelationship_RelatedShapeAspect"), py::arg("aAngleSelection"));
	cls_StepShape_AngularLocation.def("AngleSelection", (StepShape_AngleRelator (StepShape_AngularLocation::*)() const ) &StepShape_AngularLocation::AngleSelection, "Returns field AngleSelection");
	cls_StepShape_AngularLocation.def("SetAngleSelection", (void (StepShape_AngularLocation::*)(const StepShape_AngleRelator)) &StepShape_AngularLocation::SetAngleSelection, "Set field AngleSelection", py::arg("AngleSelection"));
	cls_StepShape_AngularLocation.def_static("get_type_name_", (const char * (*)()) &StepShape_AngularLocation::get_type_name, "None");
	cls_StepShape_AngularLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_AngularLocation::get_type_descriptor, "None");
	cls_StepShape_AngularLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_AngularLocation::*)() const ) &StepShape_AngularLocation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalLocationWithPath.hxx
	py::class_<StepShape_DimensionalLocationWithPath, opencascade::handle<StepShape_DimensionalLocationWithPath>, StepShape_DimensionalLocation> cls_StepShape_DimensionalLocationWithPath(mod, "StepShape_DimensionalLocationWithPath", "Representation of STEP entity DimensionalLocationWithPath");
	cls_StepShape_DimensionalLocationWithPath.def(py::init<>());
	cls_StepShape_DimensionalLocationWithPath.def("Init", (void (StepShape_DimensionalLocationWithPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalLocationWithPath::Init, "Initialize all fields (own and inherited)", py::arg("aShapeAspectRelationship_Name"), py::arg("hasShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_Description"), py::arg("aShapeAspectRelationship_RelatingShapeAspect"), py::arg("aShapeAspectRelationship_RelatedShapeAspect"), py::arg("aPath"));
	cls_StepShape_DimensionalLocationWithPath.def("Path", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalLocationWithPath::*)() const ) &StepShape_DimensionalLocationWithPath::Path, "Returns field Path");
	cls_StepShape_DimensionalLocationWithPath.def("SetPath", (void (StepShape_DimensionalLocationWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalLocationWithPath::SetPath, "Set field Path", py::arg("Path"));
	cls_StepShape_DimensionalLocationWithPath.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalLocationWithPath::get_type_name, "None");
	cls_StepShape_DimensionalLocationWithPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalLocationWithPath::get_type_descriptor, "None");
	cls_StepShape_DimensionalLocationWithPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalLocationWithPath::*)() const ) &StepShape_DimensionalLocationWithPath::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_AngularSize.hxx
	py::class_<StepShape_AngularSize, opencascade::handle<StepShape_AngularSize>, StepShape_DimensionalSize> cls_StepShape_AngularSize(mod, "StepShape_AngularSize", "Representation of STEP entity AngularSize");
	cls_StepShape_AngularSize.def(py::init<>());
	cls_StepShape_AngularSize.def("Init", (void (StepShape_AngularSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &, const StepShape_AngleRelator)) &StepShape_AngularSize::Init, "Initialize all fields (own and inherited)", py::arg("aDimensionalSize_AppliesTo"), py::arg("aDimensionalSize_Name"), py::arg("aAngleSelection"));
	cls_StepShape_AngularSize.def("AngleSelection", (StepShape_AngleRelator (StepShape_AngularSize::*)() const ) &StepShape_AngularSize::AngleSelection, "Returns field AngleSelection");
	cls_StepShape_AngularSize.def("SetAngleSelection", (void (StepShape_AngularSize::*)(const StepShape_AngleRelator)) &StepShape_AngularSize::SetAngleSelection, "Set field AngleSelection", py::arg("AngleSelection"));
	cls_StepShape_AngularSize.def_static("get_type_name_", (const char * (*)()) &StepShape_AngularSize::get_type_name, "None");
	cls_StepShape_AngularSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_AngularSize::get_type_descriptor, "None");
	cls_StepShape_AngularSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_AngularSize::*)() const ) &StepShape_AngularSize::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalSizeWithPath.hxx
	py::class_<StepShape_DimensionalSizeWithPath, opencascade::handle<StepShape_DimensionalSizeWithPath>, StepShape_DimensionalSize> cls_StepShape_DimensionalSizeWithPath(mod, "StepShape_DimensionalSizeWithPath", "Representation of STEP entity DimensionalSizeWithPath");
	cls_StepShape_DimensionalSizeWithPath.def(py::init<>());
	cls_StepShape_DimensionalSizeWithPath.def("Init", (void (StepShape_DimensionalSizeWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSizeWithPath::Init, "Initialize all fields (own and inherited)", py::arg("aDimensionalSize_AppliesTo"), py::arg("aDimensionalSize_Name"), py::arg("aPath"));
	cls_StepShape_DimensionalSizeWithPath.def("Path", (opencascade::handle<StepRepr_ShapeAspect> (StepShape_DimensionalSizeWithPath::*)() const ) &StepShape_DimensionalSizeWithPath::Path, "Returns field Path");
	cls_StepShape_DimensionalSizeWithPath.def("SetPath", (void (StepShape_DimensionalSizeWithPath::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepShape_DimensionalSizeWithPath::SetPath, "Set field Path", py::arg("Path"));
	cls_StepShape_DimensionalSizeWithPath.def_static("get_type_name_", (const char * (*)()) &StepShape_DimensionalSizeWithPath::get_type_name, "None");
	cls_StepShape_DimensionalSizeWithPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DimensionalSizeWithPath::get_type_descriptor, "None");
	cls_StepShape_DimensionalSizeWithPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DimensionalSizeWithPath::*)() const ) &StepShape_DimensionalSizeWithPath::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Edge.hxx
	py::class_<StepShape_Edge, opencascade::handle<StepShape_Edge>, StepShape_TopologicalRepresentationItem> cls_StepShape_Edge(mod, "StepShape_Edge", "None");
	cls_StepShape_Edge.def(py::init<>());
	cls_StepShape_Edge.def("Init", (void (StepShape_Edge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::Init, "None", py::arg("aName"), py::arg("aEdgeStart"), py::arg("aEdgeEnd"));
	cls_StepShape_Edge.def("SetEdgeStart", (void (StepShape_Edge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::SetEdgeStart, "None", py::arg("aEdgeStart"));
	cls_StepShape_Edge.def("EdgeStart", (opencascade::handle<StepShape_Vertex> (StepShape_Edge::*)() const ) &StepShape_Edge::EdgeStart, "None");
	cls_StepShape_Edge.def("SetEdgeEnd", (void (StepShape_Edge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_Edge::SetEdgeEnd, "None", py::arg("aEdgeEnd"));
	cls_StepShape_Edge.def("EdgeEnd", (opencascade::handle<StepShape_Vertex> (StepShape_Edge::*)() const ) &StepShape_Edge::EdgeEnd, "None");
	cls_StepShape_Edge.def_static("get_type_name_", (const char * (*)()) &StepShape_Edge::get_type_name, "None");
	cls_StepShape_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Edge::get_type_descriptor, "None");
	cls_StepShape_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Edge::*)() const ) &StepShape_Edge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_EdgeBasedWireframeModel.hxx
	py::class_<StepShape_EdgeBasedWireframeModel, opencascade::handle<StepShape_EdgeBasedWireframeModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_EdgeBasedWireframeModel(mod, "StepShape_EdgeBasedWireframeModel", "Representation of STEP entity EdgeBasedWireframeModel");
	cls_StepShape_EdgeBasedWireframeModel.def(py::init<>());
	cls_StepShape_EdgeBasedWireframeModel.def("Init", (void (StepShape_EdgeBasedWireframeModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> &)) &StepShape_EdgeBasedWireframeModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aEbwmBoundary"));
	cls_StepShape_EdgeBasedWireframeModel.def("EbwmBoundary", (opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> (StepShape_EdgeBasedWireframeModel::*)() const ) &StepShape_EdgeBasedWireframeModel::EbwmBoundary, "Returns field EbwmBoundary");
	cls_StepShape_EdgeBasedWireframeModel.def("SetEbwmBoundary", (void (StepShape_EdgeBasedWireframeModel::*)(const opencascade::handle<StepShape_HArray1OfConnectedEdgeSet> &)) &StepShape_EdgeBasedWireframeModel::SetEbwmBoundary, "Set field EbwmBoundary", py::arg("EbwmBoundary"));
	cls_StepShape_EdgeBasedWireframeModel.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeBasedWireframeModel::get_type_name, "None");
	cls_StepShape_EdgeBasedWireframeModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeBasedWireframeModel::get_type_descriptor, "None");
	cls_StepShape_EdgeBasedWireframeModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeBasedWireframeModel::*)() const ) &StepShape_EdgeBasedWireframeModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_EdgeBasedWireframeShapeRepresentation.hxx
	py::class_<StepShape_EdgeBasedWireframeShapeRepresentation, opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_EdgeBasedWireframeShapeRepresentation(mod, "StepShape_EdgeBasedWireframeShapeRepresentation", "Representation of STEP entity EdgeBasedWireframeShapeRepresentation");
	cls_StepShape_EdgeBasedWireframeShapeRepresentation.def(py::init<>());
	cls_StepShape_EdgeBasedWireframeShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeBasedWireframeShapeRepresentation::get_type_name, "None");
	cls_StepShape_EdgeBasedWireframeShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeBasedWireframeShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_EdgeBasedWireframeShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeBasedWireframeShapeRepresentation::*)() const ) &StepShape_EdgeBasedWireframeShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_EdgeCurve.hxx
	py::class_<StepShape_EdgeCurve, opencascade::handle<StepShape_EdgeCurve>, StepShape_Edge> cls_StepShape_EdgeCurve(mod, "StepShape_EdgeCurve", "None");
	cls_StepShape_EdgeCurve.def(py::init<>());
	cls_StepShape_EdgeCurve.def("Init", (void (StepShape_EdgeCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Boolean)) &StepShape_EdgeCurve::Init, "None", py::arg("aName"), py::arg("aEdgeStart"), py::arg("aEdgeEnd"), py::arg("aEdgeGeometry"), py::arg("aSameSense"));
	cls_StepShape_EdgeCurve.def("SetEdgeGeometry", (void (StepShape_EdgeCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepShape_EdgeCurve::SetEdgeGeometry, "None", py::arg("aEdgeGeometry"));
	cls_StepShape_EdgeCurve.def("EdgeGeometry", (opencascade::handle<StepGeom_Curve> (StepShape_EdgeCurve::*)() const ) &StepShape_EdgeCurve::EdgeGeometry, "None");
	cls_StepShape_EdgeCurve.def("SetSameSense", (void (StepShape_EdgeCurve::*)(const Standard_Boolean)) &StepShape_EdgeCurve::SetSameSense, "None", py::arg("aSameSense"));
	cls_StepShape_EdgeCurve.def("SameSense", (Standard_Boolean (StepShape_EdgeCurve::*)() const ) &StepShape_EdgeCurve::SameSense, "None");
	cls_StepShape_EdgeCurve.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeCurve::get_type_name, "None");
	cls_StepShape_EdgeCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeCurve::get_type_descriptor, "None");
	cls_StepShape_EdgeCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeCurve::*)() const ) &StepShape_EdgeCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Loop.hxx
	py::class_<StepShape_Loop, opencascade::handle<StepShape_Loop>, StepShape_TopologicalRepresentationItem> cls_StepShape_Loop(mod, "StepShape_Loop", "None");
	cls_StepShape_Loop.def(py::init<>());
	cls_StepShape_Loop.def_static("get_type_name_", (const char * (*)()) &StepShape_Loop::get_type_name, "None");
	cls_StepShape_Loop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Loop::get_type_descriptor, "None");
	cls_StepShape_Loop.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Loop::*)() const ) &StepShape_Loop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SweptAreaSolid.hxx
	py::class_<StepShape_SweptAreaSolid, opencascade::handle<StepShape_SweptAreaSolid>, StepShape_SolidModel> cls_StepShape_SweptAreaSolid(mod, "StepShape_SweptAreaSolid", "None");
	cls_StepShape_SweptAreaSolid.def(py::init<>());
	cls_StepShape_SweptAreaSolid.def("Init", (void (StepShape_SweptAreaSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CurveBoundedSurface> &)) &StepShape_SweptAreaSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"));
	cls_StepShape_SweptAreaSolid.def("SetSweptArea", (void (StepShape_SweptAreaSolid::*)(const opencascade::handle<StepGeom_CurveBoundedSurface> &)) &StepShape_SweptAreaSolid::SetSweptArea, "None", py::arg("aSweptArea"));
	cls_StepShape_SweptAreaSolid.def("SweptArea", (opencascade::handle<StepGeom_CurveBoundedSurface> (StepShape_SweptAreaSolid::*)() const ) &StepShape_SweptAreaSolid::SweptArea, "None");
	cls_StepShape_SweptAreaSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_SweptAreaSolid::get_type_name, "None");
	cls_StepShape_SweptAreaSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SweptAreaSolid::get_type_descriptor, "None");
	cls_StepShape_SweptAreaSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SweptAreaSolid::*)() const ) &StepShape_SweptAreaSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SweptFaceSolid.hxx
	py::class_<StepShape_SweptFaceSolid, opencascade::handle<StepShape_SweptFaceSolid>, StepShape_SolidModel> cls_StepShape_SweptFaceSolid(mod, "StepShape_SweptFaceSolid", "None");
	cls_StepShape_SweptFaceSolid.def(py::init<>());
	cls_StepShape_SweptFaceSolid.def("Init", (void (StepShape_SweptFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_SweptFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"));
	cls_StepShape_SweptFaceSolid.def("SetSweptFace", (void (StepShape_SweptFaceSolid::*)(const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_SweptFaceSolid::SetSweptFace, "None", py::arg("aSweptArea"));
	cls_StepShape_SweptFaceSolid.def("SweptFace", (opencascade::handle<StepShape_FaceSurface> (StepShape_SweptFaceSolid::*)() const ) &StepShape_SweptFaceSolid::SweptFace, "None");
	cls_StepShape_SweptFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_SweptFaceSolid::get_type_name, "None");
	cls_StepShape_SweptFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SweptFaceSolid::get_type_descriptor, "None");
	cls_StepShape_SweptFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SweptFaceSolid::*)() const ) &StepShape_SweptFaceSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Face.hxx
	py::class_<StepShape_Face, opencascade::handle<StepShape_Face>, StepShape_TopologicalRepresentationItem> cls_StepShape_Face(mod, "StepShape_Face", "None");
	cls_StepShape_Face.def(py::init<>());
	cls_StepShape_Face.def("Init", (void (StepShape_Face::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &)) &StepShape_Face::Init, "None", py::arg("aName"), py::arg("aBounds"));
	cls_StepShape_Face.def("SetBounds", (void (StepShape_Face::*)(const opencascade::handle<StepShape_HArray1OfFaceBound> &)) &StepShape_Face::SetBounds, "None", py::arg("aBounds"));
	cls_StepShape_Face.def("Bounds", (opencascade::handle<StepShape_HArray1OfFaceBound> (StepShape_Face::*)() const ) &StepShape_Face::Bounds, "None");
	cls_StepShape_Face.def("BoundsValue", (opencascade::handle<StepShape_FaceBound> (StepShape_Face::*)(const Standard_Integer) const ) &StepShape_Face::BoundsValue, "None", py::arg("num"));
	cls_StepShape_Face.def("NbBounds", (Standard_Integer (StepShape_Face::*)() const ) &StepShape_Face::NbBounds, "None");
	cls_StepShape_Face.def_static("get_type_name_", (const char * (*)()) &StepShape_Face::get_type_name, "None");
	cls_StepShape_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Face::get_type_descriptor, "None");
	cls_StepShape_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Face::*)() const ) &StepShape_Face::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FaceBasedSurfaceModel.hxx
	py::class_<StepShape_FaceBasedSurfaceModel, opencascade::handle<StepShape_FaceBasedSurfaceModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_FaceBasedSurfaceModel(mod, "StepShape_FaceBasedSurfaceModel", "Representation of STEP entity FaceBasedSurfaceModel");
	cls_StepShape_FaceBasedSurfaceModel.def(py::init<>());
	cls_StepShape_FaceBasedSurfaceModel.def("Init", (void (StepShape_FaceBasedSurfaceModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfConnectedFaceSet> &)) &StepShape_FaceBasedSurfaceModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFbsmFaces"));
	cls_StepShape_FaceBasedSurfaceModel.def("FbsmFaces", (opencascade::handle<StepShape_HArray1OfConnectedFaceSet> (StepShape_FaceBasedSurfaceModel::*)() const ) &StepShape_FaceBasedSurfaceModel::FbsmFaces, "Returns field FbsmFaces");
	cls_StepShape_FaceBasedSurfaceModel.def("SetFbsmFaces", (void (StepShape_FaceBasedSurfaceModel::*)(const opencascade::handle<StepShape_HArray1OfConnectedFaceSet> &)) &StepShape_FaceBasedSurfaceModel::SetFbsmFaces, "Set field FbsmFaces", py::arg("FbsmFaces"));
	cls_StepShape_FaceBasedSurfaceModel.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceBasedSurfaceModel::get_type_name, "None");
	cls_StepShape_FaceBasedSurfaceModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceBasedSurfaceModel::get_type_descriptor, "None");
	cls_StepShape_FaceBasedSurfaceModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceBasedSurfaceModel::*)() const ) &StepShape_FaceBasedSurfaceModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FaceBound.hxx
	py::class_<StepShape_FaceBound, opencascade::handle<StepShape_FaceBound>, StepShape_TopologicalRepresentationItem> cls_StepShape_FaceBound(mod, "StepShape_FaceBound", "None");
	cls_StepShape_FaceBound.def(py::init<>());
	cls_StepShape_FaceBound.def("Init", (void (StepShape_FaceBound::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Loop> &, const Standard_Boolean)) &StepShape_FaceBound::Init, "None", py::arg("aName"), py::arg("aBound"), py::arg("aOrientation"));
	cls_StepShape_FaceBound.def("SetBound", (void (StepShape_FaceBound::*)(const opencascade::handle<StepShape_Loop> &)) &StepShape_FaceBound::SetBound, "None", py::arg("aBound"));
	cls_StepShape_FaceBound.def("Bound", (opencascade::handle<StepShape_Loop> (StepShape_FaceBound::*)() const ) &StepShape_FaceBound::Bound, "None");
	cls_StepShape_FaceBound.def("SetOrientation", (void (StepShape_FaceBound::*)(const Standard_Boolean)) &StepShape_FaceBound::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_FaceBound.def("Orientation", (Standard_Boolean (StepShape_FaceBound::*)() const ) &StepShape_FaceBound::Orientation, "None");
	cls_StepShape_FaceBound.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceBound::get_type_name, "None");
	cls_StepShape_FaceBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceBound::get_type_descriptor, "None");
	cls_StepShape_FaceBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceBound::*)() const ) &StepShape_FaceBound::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FaceOuterBound.hxx
	py::class_<StepShape_FaceOuterBound, opencascade::handle<StepShape_FaceOuterBound>, StepShape_FaceBound> cls_StepShape_FaceOuterBound(mod, "StepShape_FaceOuterBound", "None");
	cls_StepShape_FaceOuterBound.def(py::init<>());
	cls_StepShape_FaceOuterBound.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceOuterBound::get_type_name, "None");
	cls_StepShape_FaceOuterBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceOuterBound::get_type_descriptor, "None");
	cls_StepShape_FaceOuterBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceOuterBound::*)() const ) &StepShape_FaceOuterBound::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FaceSurface.hxx
	py::class_<StepShape_FaceSurface, opencascade::handle<StepShape_FaceSurface>, StepShape_Face> cls_StepShape_FaceSurface(mod, "StepShape_FaceSurface", "None");
	cls_StepShape_FaceSurface.def(py::init<>());
	cls_StepShape_FaceSurface.def("Init", (void (StepShape_FaceSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean)) &StepShape_FaceSurface::Init, "None", py::arg("aName"), py::arg("aBounds"), py::arg("aFaceGeometry"), py::arg("aSameSense"));
	cls_StepShape_FaceSurface.def("SetFaceGeometry", (void (StepShape_FaceSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepShape_FaceSurface::SetFaceGeometry, "None", py::arg("aFaceGeometry"));
	cls_StepShape_FaceSurface.def("FaceGeometry", (opencascade::handle<StepGeom_Surface> (StepShape_FaceSurface::*)() const ) &StepShape_FaceSurface::FaceGeometry, "None");
	cls_StepShape_FaceSurface.def("SetSameSense", (void (StepShape_FaceSurface::*)(const Standard_Boolean)) &StepShape_FaceSurface::SetSameSense, "None", py::arg("aSameSense"));
	cls_StepShape_FaceSurface.def("SameSense", (Standard_Boolean (StepShape_FaceSurface::*)() const ) &StepShape_FaceSurface::SameSense, "None");
	cls_StepShape_FaceSurface.def_static("get_type_name_", (const char * (*)()) &StepShape_FaceSurface::get_type_name, "None");
	cls_StepShape_FaceSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FaceSurface::get_type_descriptor, "None");
	cls_StepShape_FaceSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FaceSurface::*)() const ) &StepShape_FaceSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ManifoldSolidBrep.hxx
	py::class_<StepShape_ManifoldSolidBrep, opencascade::handle<StepShape_ManifoldSolidBrep>, StepShape_SolidModel> cls_StepShape_ManifoldSolidBrep(mod, "StepShape_ManifoldSolidBrep", "None");
	cls_StepShape_ManifoldSolidBrep.def(py::init<>());
	cls_StepShape_ManifoldSolidBrep.def("Init", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &)) &StepShape_ManifoldSolidBrep::Init, "None", py::arg("aName"), py::arg("aOuter"));
	cls_StepShape_ManifoldSolidBrep.def("Init", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ManifoldSolidBrep::Init, "None", py::arg("aName"), py::arg("aOuter"));
	cls_StepShape_ManifoldSolidBrep.def("SetOuter", (void (StepShape_ManifoldSolidBrep::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &)) &StepShape_ManifoldSolidBrep::SetOuter, "None", py::arg("aOuter"));
	cls_StepShape_ManifoldSolidBrep.def("Outer", (opencascade::handle<StepShape_ConnectedFaceSet> (StepShape_ManifoldSolidBrep::*)() const ) &StepShape_ManifoldSolidBrep::Outer, "None");
	cls_StepShape_ManifoldSolidBrep.def_static("get_type_name_", (const char * (*)()) &StepShape_ManifoldSolidBrep::get_type_name, "None");
	cls_StepShape_ManifoldSolidBrep.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ManifoldSolidBrep::get_type_descriptor, "None");
	cls_StepShape_ManifoldSolidBrep.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ManifoldSolidBrep::*)() const ) &StepShape_ManifoldSolidBrep::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FacetedBrepAndBrepWithVoids.hxx
	py::class_<StepShape_FacetedBrepAndBrepWithVoids, opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids>, StepShape_ManifoldSolidBrep> cls_StepShape_FacetedBrepAndBrepWithVoids(mod, "StepShape_FacetedBrepAndBrepWithVoids", "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def(py::init<>());
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("Init", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<StepShape_BrepWithVoids> &)) &StepShape_FacetedBrepAndBrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aFacetedBrep"), py::arg("aBrepWithVoids"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("Init", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_FacetedBrepAndBrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aVoids"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetFacetedBrep", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_FacetedBrep> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetFacetedBrep, "None", py::arg("aFacetedBrep"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("FacetedBrep", (opencascade::handle<StepShape_FacetedBrep> (StepShape_FacetedBrepAndBrepWithVoids::*)() const ) &StepShape_FacetedBrepAndBrepWithVoids::FacetedBrep, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetBrepWithVoids", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetBrepWithVoids, "None", py::arg("aBrepWithVoids"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("BrepWithVoids", (opencascade::handle<StepShape_BrepWithVoids> (StepShape_FacetedBrepAndBrepWithVoids::*)() const ) &StepShape_FacetedBrepAndBrepWithVoids::BrepWithVoids, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("SetVoids", (void (StepShape_FacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_FacetedBrepAndBrepWithVoids::SetVoids, "None", py::arg("aVoids"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("Voids", (opencascade::handle<StepShape_HArray1OfOrientedClosedShell> (StepShape_FacetedBrepAndBrepWithVoids::*)() const ) &StepShape_FacetedBrepAndBrepWithVoids::Voids, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("VoidsValue", (opencascade::handle<StepShape_OrientedClosedShell> (StepShape_FacetedBrepAndBrepWithVoids::*)(const Standard_Integer) const ) &StepShape_FacetedBrepAndBrepWithVoids::VoidsValue, "None", py::arg("num"));
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("NbVoids", (Standard_Integer (StepShape_FacetedBrepAndBrepWithVoids::*)() const ) &StepShape_FacetedBrepAndBrepWithVoids::NbVoids, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def_static("get_type_name_", (const char * (*)()) &StepShape_FacetedBrepAndBrepWithVoids::get_type_name, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FacetedBrepAndBrepWithVoids::get_type_descriptor, "None");
	cls_StepShape_FacetedBrepAndBrepWithVoids.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FacetedBrepAndBrepWithVoids::*)() const ) &StepShape_FacetedBrepAndBrepWithVoids::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FacetedBrepShapeRepresentation.hxx
	py::class_<StepShape_FacetedBrepShapeRepresentation, opencascade::handle<StepShape_FacetedBrepShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_FacetedBrepShapeRepresentation(mod, "StepShape_FacetedBrepShapeRepresentation", "None");
	cls_StepShape_FacetedBrepShapeRepresentation.def(py::init<>());
	cls_StepShape_FacetedBrepShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_FacetedBrepShapeRepresentation::get_type_name, "None");
	cls_StepShape_FacetedBrepShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FacetedBrepShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_FacetedBrepShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FacetedBrepShapeRepresentation::*)() const ) &StepShape_FacetedBrepShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_GeometricallyBoundedSurfaceShapeRepresentation.hxx
	py::class_<StepShape_GeometricallyBoundedSurfaceShapeRepresentation, opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_GeometricallyBoundedSurfaceShapeRepresentation(mod, "StepShape_GeometricallyBoundedSurfaceShapeRepresentation", "None");
	cls_StepShape_GeometricallyBoundedSurfaceShapeRepresentation.def(py::init<>());
	cls_StepShape_GeometricallyBoundedSurfaceShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_GeometricallyBoundedSurfaceShapeRepresentation::get_type_name, "None");
	cls_StepShape_GeometricallyBoundedSurfaceShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_GeometricallyBoundedSurfaceShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_GeometricallyBoundedSurfaceShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_GeometricallyBoundedSurfaceShapeRepresentation::*)() const ) &StepShape_GeometricallyBoundedSurfaceShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_GeometricallyBoundedWireframeShapeRepresentation.hxx
	py::class_<StepShape_GeometricallyBoundedWireframeShapeRepresentation, opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_GeometricallyBoundedWireframeShapeRepresentation(mod, "StepShape_GeometricallyBoundedWireframeShapeRepresentation", "None");
	cls_StepShape_GeometricallyBoundedWireframeShapeRepresentation.def(py::init<>());
	cls_StepShape_GeometricallyBoundedWireframeShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_GeometricallyBoundedWireframeShapeRepresentation::get_type_name, "None");
	cls_StepShape_GeometricallyBoundedWireframeShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_GeometricallyBoundedWireframeShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_GeometricallyBoundedWireframeShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_GeometricallyBoundedWireframeShapeRepresentation::*)() const ) &StepShape_GeometricallyBoundedWireframeShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_GeometricSet.hxx
	py::class_<StepShape_GeometricSet, opencascade::handle<StepShape_GeometricSet>, StepGeom_GeometricRepresentationItem> cls_StepShape_GeometricSet(mod, "StepShape_GeometricSet", "None");
	cls_StepShape_GeometricSet.def(py::init<>());
	cls_StepShape_GeometricSet.def("Init", (void (StepShape_GeometricSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfGeometricSetSelect> &)) &StepShape_GeometricSet::Init, "None", py::arg("aName"), py::arg("aElements"));
	cls_StepShape_GeometricSet.def("SetElements", (void (StepShape_GeometricSet::*)(const opencascade::handle<StepShape_HArray1OfGeometricSetSelect> &)) &StepShape_GeometricSet::SetElements, "None", py::arg("aElements"));
	cls_StepShape_GeometricSet.def("Elements", (opencascade::handle<StepShape_HArray1OfGeometricSetSelect> (StepShape_GeometricSet::*)() const ) &StepShape_GeometricSet::Elements, "None");
	cls_StepShape_GeometricSet.def("ElementsValue", (StepShape_GeometricSetSelect (StepShape_GeometricSet::*)(const Standard_Integer) const ) &StepShape_GeometricSet::ElementsValue, "None", py::arg("num"));
	cls_StepShape_GeometricSet.def("NbElements", (Standard_Integer (StepShape_GeometricSet::*)() const ) &StepShape_GeometricSet::NbElements, "None");
	cls_StepShape_GeometricSet.def_static("get_type_name_", (const char * (*)()) &StepShape_GeometricSet::get_type_name, "None");
	cls_StepShape_GeometricSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_GeometricSet::get_type_descriptor, "None");
	cls_StepShape_GeometricSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_GeometricSet::*)() const ) &StepShape_GeometricSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_GeometricCurveSet.hxx
	py::class_<StepShape_GeometricCurveSet, opencascade::handle<StepShape_GeometricCurveSet>, StepShape_GeometricSet> cls_StepShape_GeometricCurveSet(mod, "StepShape_GeometricCurveSet", "None");
	cls_StepShape_GeometricCurveSet.def(py::init<>());
	cls_StepShape_GeometricCurveSet.def_static("get_type_name_", (const char * (*)()) &StepShape_GeometricCurveSet::get_type_name, "None");
	cls_StepShape_GeometricCurveSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_GeometricCurveSet::get_type_descriptor, "None");
	cls_StepShape_GeometricCurveSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_GeometricCurveSet::*)() const ) &StepShape_GeometricCurveSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BoxedHalfSpace.hxx
	py::class_<StepShape_BoxedHalfSpace, opencascade::handle<StepShape_BoxedHalfSpace>, StepShape_HalfSpaceSolid> cls_StepShape_BoxedHalfSpace(mod, "StepShape_BoxedHalfSpace", "None");
	cls_StepShape_BoxedHalfSpace.def(py::init<>());
	cls_StepShape_BoxedHalfSpace.def("Init", (void (StepShape_BoxedHalfSpace::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, const opencascade::handle<StepShape_BoxDomain> &)) &StepShape_BoxedHalfSpace::Init, "None", py::arg("aName"), py::arg("aBaseSurface"), py::arg("aAgreementFlag"), py::arg("aEnclosure"));
	cls_StepShape_BoxedHalfSpace.def("SetEnclosure", (void (StepShape_BoxedHalfSpace::*)(const opencascade::handle<StepShape_BoxDomain> &)) &StepShape_BoxedHalfSpace::SetEnclosure, "None", py::arg("aEnclosure"));
	cls_StepShape_BoxedHalfSpace.def("Enclosure", (opencascade::handle<StepShape_BoxDomain> (StepShape_BoxedHalfSpace::*)() const ) &StepShape_BoxedHalfSpace::Enclosure, "None");
	cls_StepShape_BoxedHalfSpace.def_static("get_type_name_", (const char * (*)()) &StepShape_BoxedHalfSpace::get_type_name, "None");
	cls_StepShape_BoxedHalfSpace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BoxedHalfSpace::get_type_descriptor, "None");
	cls_StepShape_BoxedHalfSpace.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BoxedHalfSpace::*)() const ) &StepShape_BoxedHalfSpace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_LimitsAndFits.hxx
	py::class_<StepShape_LimitsAndFits, opencascade::handle<StepShape_LimitsAndFits>, Standard_Transient> cls_StepShape_LimitsAndFits(mod, "StepShape_LimitsAndFits", "Added for Dimensional Tolerances");
	cls_StepShape_LimitsAndFits.def(py::init<>());
	cls_StepShape_LimitsAndFits.def("Init", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::Init, "None", py::arg("form_variance"), py::arg("zone_variance"), py::arg("grade"), py::arg("source"));
	cls_StepShape_LimitsAndFits.def("FormVariance", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const ) &StepShape_LimitsAndFits::FormVariance, "None");
	cls_StepShape_LimitsAndFits.def("SetFormVariance", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetFormVariance, "None", py::arg("form_variance"));
	cls_StepShape_LimitsAndFits.def("ZoneVariance", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const ) &StepShape_LimitsAndFits::ZoneVariance, "None");
	cls_StepShape_LimitsAndFits.def("SetZoneVariance", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetZoneVariance, "None", py::arg("zone_variance"));
	cls_StepShape_LimitsAndFits.def("Grade", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const ) &StepShape_LimitsAndFits::Grade, "None");
	cls_StepShape_LimitsAndFits.def("SetGrade", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetGrade, "None", py::arg("grade"));
	cls_StepShape_LimitsAndFits.def("Source", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const ) &StepShape_LimitsAndFits::Source, "None");
	cls_StepShape_LimitsAndFits.def("SetSource", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetSource, "None", py::arg("source"));
	cls_StepShape_LimitsAndFits.def_static("get_type_name_", (const char * (*)()) &StepShape_LimitsAndFits::get_type_name, "None");
	cls_StepShape_LimitsAndFits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_LimitsAndFits::get_type_descriptor, "None");
	cls_StepShape_LimitsAndFits.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_LimitsAndFits::*)() const ) &StepShape_LimitsAndFits::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_EdgeLoop.hxx
	py::class_<StepShape_EdgeLoop, opencascade::handle<StepShape_EdgeLoop>, StepShape_Loop> cls_StepShape_EdgeLoop(mod, "StepShape_EdgeLoop", "None");
	cls_StepShape_EdgeLoop.def(py::init<>());
	cls_StepShape_EdgeLoop.def("Init", (void (StepShape_EdgeLoop::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_EdgeLoop::Init, "None", py::arg("aName"), py::arg("aEdgeList"));
	cls_StepShape_EdgeLoop.def("SetEdgeList", (void (StepShape_EdgeLoop::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_EdgeLoop::SetEdgeList, "None", py::arg("aEdgeList"));
	cls_StepShape_EdgeLoop.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_EdgeLoop::*)() const ) &StepShape_EdgeLoop::EdgeList, "None");
	cls_StepShape_EdgeLoop.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_EdgeLoop::*)(const Standard_Integer) const ) &StepShape_EdgeLoop::EdgeListValue, "None", py::arg("num"));
	cls_StepShape_EdgeLoop.def("NbEdgeList", (Standard_Integer (StepShape_EdgeLoop::*)() const ) &StepShape_EdgeLoop::NbEdgeList, "None");
	cls_StepShape_EdgeLoop.def_static("get_type_name_", (const char * (*)()) &StepShape_EdgeLoop::get_type_name, "None");
	cls_StepShape_EdgeLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_EdgeLoop::get_type_descriptor, "None");
	cls_StepShape_EdgeLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_EdgeLoop::*)() const ) &StepShape_EdgeLoop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_LoopAndPath.hxx
	py::class_<StepShape_LoopAndPath, opencascade::handle<StepShape_LoopAndPath>, StepShape_TopologicalRepresentationItem> cls_StepShape_LoopAndPath(mod, "StepShape_LoopAndPath", "None");
	cls_StepShape_LoopAndPath.def(py::init<>());
	cls_StepShape_LoopAndPath.def("Init", (void (StepShape_LoopAndPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Loop> &, const opencascade::handle<StepShape_Path> &)) &StepShape_LoopAndPath::Init, "None", py::arg("aName"), py::arg("aLoop"), py::arg("aPath"));
	cls_StepShape_LoopAndPath.def("Init", (void (StepShape_LoopAndPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_LoopAndPath::Init, "None", py::arg("aName"), py::arg("aEdgeList"));
	cls_StepShape_LoopAndPath.def("SetLoop", (void (StepShape_LoopAndPath::*)(const opencascade::handle<StepShape_Loop> &)) &StepShape_LoopAndPath::SetLoop, "None", py::arg("aLoop"));
	cls_StepShape_LoopAndPath.def("Loop", (opencascade::handle<StepShape_Loop> (StepShape_LoopAndPath::*)() const ) &StepShape_LoopAndPath::Loop, "None");
	cls_StepShape_LoopAndPath.def("SetPath", (void (StepShape_LoopAndPath::*)(const opencascade::handle<StepShape_Path> &)) &StepShape_LoopAndPath::SetPath, "None", py::arg("aPath"));
	cls_StepShape_LoopAndPath.def("Path", (opencascade::handle<StepShape_Path> (StepShape_LoopAndPath::*)() const ) &StepShape_LoopAndPath::Path, "None");
	cls_StepShape_LoopAndPath.def("SetEdgeList", (void (StepShape_LoopAndPath::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_LoopAndPath::SetEdgeList, "None", py::arg("aEdgeList"));
	cls_StepShape_LoopAndPath.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_LoopAndPath::*)() const ) &StepShape_LoopAndPath::EdgeList, "None");
	cls_StepShape_LoopAndPath.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_LoopAndPath::*)(const Standard_Integer) const ) &StepShape_LoopAndPath::EdgeListValue, "None", py::arg("num"));
	cls_StepShape_LoopAndPath.def("NbEdgeList", (Standard_Integer (StepShape_LoopAndPath::*)() const ) &StepShape_LoopAndPath::NbEdgeList, "None");
	cls_StepShape_LoopAndPath.def_static("get_type_name_", (const char * (*)()) &StepShape_LoopAndPath::get_type_name, "None");
	cls_StepShape_LoopAndPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_LoopAndPath::get_type_descriptor, "None");
	cls_StepShape_LoopAndPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_LoopAndPath::*)() const ) &StepShape_LoopAndPath::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BrepWithVoids.hxx
	py::class_<StepShape_BrepWithVoids, opencascade::handle<StepShape_BrepWithVoids>, StepShape_ManifoldSolidBrep> cls_StepShape_BrepWithVoids(mod, "StepShape_BrepWithVoids", "None");
	cls_StepShape_BrepWithVoids.def(py::init<>());
	cls_StepShape_BrepWithVoids.def("Init", (void (StepShape_BrepWithVoids::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_BrepWithVoids::Init, "None", py::arg("aName"), py::arg("aOuter"), py::arg("aVoids"));
	cls_StepShape_BrepWithVoids.def("SetVoids", (void (StepShape_BrepWithVoids::*)(const opencascade::handle<StepShape_HArray1OfOrientedClosedShell> &)) &StepShape_BrepWithVoids::SetVoids, "None", py::arg("aVoids"));
	cls_StepShape_BrepWithVoids.def("Voids", (opencascade::handle<StepShape_HArray1OfOrientedClosedShell> (StepShape_BrepWithVoids::*)() const ) &StepShape_BrepWithVoids::Voids, "None");
	cls_StepShape_BrepWithVoids.def("VoidsValue", (opencascade::handle<StepShape_OrientedClosedShell> (StepShape_BrepWithVoids::*)(const Standard_Integer) const ) &StepShape_BrepWithVoids::VoidsValue, "None", py::arg("num"));
	cls_StepShape_BrepWithVoids.def("NbVoids", (Standard_Integer (StepShape_BrepWithVoids::*)() const ) &StepShape_BrepWithVoids::NbVoids, "None");
	cls_StepShape_BrepWithVoids.def_static("get_type_name_", (const char * (*)()) &StepShape_BrepWithVoids::get_type_name, "None");
	cls_StepShape_BrepWithVoids.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BrepWithVoids::get_type_descriptor, "None");
	cls_StepShape_BrepWithVoids.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BrepWithVoids::*)() const ) &StepShape_BrepWithVoids::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ManifoldSurfaceShapeRepresentation.hxx
	py::class_<StepShape_ManifoldSurfaceShapeRepresentation, opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_ManifoldSurfaceShapeRepresentation(mod, "StepShape_ManifoldSurfaceShapeRepresentation", "None");
	cls_StepShape_ManifoldSurfaceShapeRepresentation.def(py::init<>());
	cls_StepShape_ManifoldSurfaceShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ManifoldSurfaceShapeRepresentation::get_type_name, "None");
	cls_StepShape_ManifoldSurfaceShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ManifoldSurfaceShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_ManifoldSurfaceShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ManifoldSurfaceShapeRepresentation::*)() const ) &StepShape_ManifoldSurfaceShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_MeasureQualification.hxx
	py::class_<StepShape_MeasureQualification, opencascade::handle<StepShape_MeasureQualification>, Standard_Transient> cls_StepShape_MeasureQualification(mod, "StepShape_MeasureQualification", "Added for Dimensional Tolerances");
	cls_StepShape_MeasureQualification.def(py::init<>());
	cls_StepShape_MeasureQualification.def("Init", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureQualification::Init, "None", py::arg("name"), py::arg("description"), py::arg("qualified_measure"), py::arg("qualifiers"));
	cls_StepShape_MeasureQualification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::Name, "None");
	cls_StepShape_MeasureQualification.def("SetName", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_MeasureQualification::SetName, "None", py::arg("name"));
	cls_StepShape_MeasureQualification.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::Description, "None");
	cls_StepShape_MeasureQualification.def("SetDescription", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_MeasureQualification::SetDescription, "None", py::arg("description"));
	cls_StepShape_MeasureQualification.def("QualifiedMeasure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::QualifiedMeasure, "None");
	cls_StepShape_MeasureQualification.def("SetQualifiedMeasure", (void (StepShape_MeasureQualification::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_MeasureQualification::SetQualifiedMeasure, "None", py::arg("qualified_measure"));
	cls_StepShape_MeasureQualification.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::Qualifiers, "None");
	cls_StepShape_MeasureQualification.def("NbQualifiers", (Standard_Integer (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::NbQualifiers, "None");
	cls_StepShape_MeasureQualification.def("SetQualifiers", (void (StepShape_MeasureQualification::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureQualification::SetQualifiers, "None", py::arg("qualifiers"));
	cls_StepShape_MeasureQualification.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_MeasureQualification::*)(const Standard_Integer) const ) &StepShape_MeasureQualification::QualifiersValue, "None", py::arg("num"));
	cls_StepShape_MeasureQualification.def("SetQualifiersValue", (void (StepShape_MeasureQualification::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_MeasureQualification::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
	cls_StepShape_MeasureQualification.def_static("get_type_name_", (const char * (*)()) &StepShape_MeasureQualification::get_type_name, "None");
	cls_StepShape_MeasureQualification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_MeasureQualification::get_type_descriptor, "None");
	cls_StepShape_MeasureQualification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_MeasureQualification::*)() const ) &StepShape_MeasureQualification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.hxx
	py::class_<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem, opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem>, StepRepr_RepresentationItem> cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem(mod, "StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem", "Added for Dimensional Tolerances Complex Type between MeasureRepresentationItem and QualifiedRepresentationItem");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def(py::init<>());
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Init", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Init, "None", py::arg("aName"), py::arg("aValueComponent"), py::arg("aUnitComponent"), py::arg("qualifiers"));
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetMeasure", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetMeasure, "None", py::arg("Measure"));
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Measure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const ) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Measure, "None");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const ) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Qualifiers, "None");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("NbQualifiers", (Standard_Integer (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const ) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::NbQualifiers, "None");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetQualifiers", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetQualifiers, "None", py::arg("qualifiers"));
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const Standard_Integer) const ) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::QualifiersValue, "None", py::arg("num"));
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetQualifiersValue", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::get_type_name, "None");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::get_type_descriptor, "None");
	cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const ) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_NonManifoldSurfaceShapeRepresentation.hxx
	py::class_<StepShape_NonManifoldSurfaceShapeRepresentation, opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_NonManifoldSurfaceShapeRepresentation(mod, "StepShape_NonManifoldSurfaceShapeRepresentation", "Representation of STEP entity NonManifoldSurfaceShapeRepresentation");
	cls_StepShape_NonManifoldSurfaceShapeRepresentation.def(py::init<>());
	cls_StepShape_NonManifoldSurfaceShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_NonManifoldSurfaceShapeRepresentation::get_type_name, "None");
	cls_StepShape_NonManifoldSurfaceShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_NonManifoldSurfaceShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_NonManifoldSurfaceShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_NonManifoldSurfaceShapeRepresentation::*)() const ) &StepShape_NonManifoldSurfaceShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OpenShell.hxx
	py::class_<StepShape_OpenShell, opencascade::handle<StepShape_OpenShell>, StepShape_ConnectedFaceSet> cls_StepShape_OpenShell(mod, "StepShape_OpenShell", "None");
	cls_StepShape_OpenShell.def(py::init<>());
	cls_StepShape_OpenShell.def_static("get_type_name_", (const char * (*)()) &StepShape_OpenShell::get_type_name, "None");
	cls_StepShape_OpenShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OpenShell::get_type_descriptor, "None");
	cls_StepShape_OpenShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OpenShell::*)() const ) &StepShape_OpenShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OrientedClosedShell.hxx
	py::class_<StepShape_OrientedClosedShell, opencascade::handle<StepShape_OrientedClosedShell>, StepShape_ClosedShell> cls_StepShape_OrientedClosedShell(mod, "StepShape_OrientedClosedShell", "None");
	cls_StepShape_OrientedClosedShell.def(py::init<>());
	cls_StepShape_OrientedClosedShell.def("Init", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_ClosedShell> &, const Standard_Boolean)) &StepShape_OrientedClosedShell::Init, "None", py::arg("aName"), py::arg("aClosedShellElement"), py::arg("aOrientation"));
	cls_StepShape_OrientedClosedShell.def("SetClosedShellElement", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<StepShape_ClosedShell> &)) &StepShape_OrientedClosedShell::SetClosedShellElement, "None", py::arg("aClosedShellElement"));
	cls_StepShape_OrientedClosedShell.def("ClosedShellElement", (opencascade::handle<StepShape_ClosedShell> (StepShape_OrientedClosedShell::*)() const ) &StepShape_OrientedClosedShell::ClosedShellElement, "None");
	cls_StepShape_OrientedClosedShell.def("SetOrientation", (void (StepShape_OrientedClosedShell::*)(const Standard_Boolean)) &StepShape_OrientedClosedShell::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_OrientedClosedShell.def("Orientation", (Standard_Boolean (StepShape_OrientedClosedShell::*)() const ) &StepShape_OrientedClosedShell::Orientation, "None");
	cls_StepShape_OrientedClosedShell.def("SetCfsFaces", (void (StepShape_OrientedClosedShell::*)(const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_OrientedClosedShell::SetCfsFaces, "None", py::arg("aCfsFaces"));
	cls_StepShape_OrientedClosedShell.def("CfsFaces", (opencascade::handle<StepShape_HArray1OfFace> (StepShape_OrientedClosedShell::*)() const ) &StepShape_OrientedClosedShell::CfsFaces, "None");
	cls_StepShape_OrientedClosedShell.def("CfsFacesValue", (opencascade::handle<StepShape_Face> (StepShape_OrientedClosedShell::*)(const Standard_Integer) const ) &StepShape_OrientedClosedShell::CfsFacesValue, "None", py::arg("num"));
	cls_StepShape_OrientedClosedShell.def("NbCfsFaces", (Standard_Integer (StepShape_OrientedClosedShell::*)() const ) &StepShape_OrientedClosedShell::NbCfsFaces, "None");
	cls_StepShape_OrientedClosedShell.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedClosedShell::get_type_name, "None");
	cls_StepShape_OrientedClosedShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedClosedShell::get_type_descriptor, "None");
	cls_StepShape_OrientedClosedShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedClosedShell::*)() const ) &StepShape_OrientedClosedShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OrientedEdge.hxx
	py::class_<StepShape_OrientedEdge, opencascade::handle<StepShape_OrientedEdge>, StepShape_Edge> cls_StepShape_OrientedEdge(mod, "StepShape_OrientedEdge", "None");
	cls_StepShape_OrientedEdge.def(py::init<>());
	cls_StepShape_OrientedEdge.def("Init", (void (StepShape_OrientedEdge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Edge> &, const Standard_Boolean)) &StepShape_OrientedEdge::Init, "None", py::arg("aName"), py::arg("aEdgeElement"), py::arg("aOrientation"));
	cls_StepShape_OrientedEdge.def("SetEdgeElement", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Edge> &)) &StepShape_OrientedEdge::SetEdgeElement, "None", py::arg("aEdgeElement"));
	cls_StepShape_OrientedEdge.def("EdgeElement", (opencascade::handle<StepShape_Edge> (StepShape_OrientedEdge::*)() const ) &StepShape_OrientedEdge::EdgeElement, "None");
	cls_StepShape_OrientedEdge.def("SetOrientation", (void (StepShape_OrientedEdge::*)(const Standard_Boolean)) &StepShape_OrientedEdge::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_OrientedEdge.def("Orientation", (Standard_Boolean (StepShape_OrientedEdge::*)() const ) &StepShape_OrientedEdge::Orientation, "None");
	cls_StepShape_OrientedEdge.def("SetEdgeStart", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_OrientedEdge::SetEdgeStart, "None", py::arg("aEdgeStart"));
	cls_StepShape_OrientedEdge.def("EdgeStart", (opencascade::handle<StepShape_Vertex> (StepShape_OrientedEdge::*)() const ) &StepShape_OrientedEdge::EdgeStart, "None");
	cls_StepShape_OrientedEdge.def("SetEdgeEnd", (void (StepShape_OrientedEdge::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_OrientedEdge::SetEdgeEnd, "None", py::arg("aEdgeEnd"));
	cls_StepShape_OrientedEdge.def("EdgeEnd", (opencascade::handle<StepShape_Vertex> (StepShape_OrientedEdge::*)() const ) &StepShape_OrientedEdge::EdgeEnd, "None");
	cls_StepShape_OrientedEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedEdge::get_type_name, "None");
	cls_StepShape_OrientedEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedEdge::get_type_descriptor, "None");
	cls_StepShape_OrientedEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedEdge::*)() const ) &StepShape_OrientedEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OrientedFace.hxx
	py::class_<StepShape_OrientedFace, opencascade::handle<StepShape_OrientedFace>, StepShape_Face> cls_StepShape_OrientedFace(mod, "StepShape_OrientedFace", "None");
	cls_StepShape_OrientedFace.def(py::init<>());
	cls_StepShape_OrientedFace.def("Init", (void (StepShape_OrientedFace::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Face> &, const Standard_Boolean)) &StepShape_OrientedFace::Init, "None", py::arg("aName"), py::arg("aFaceElement"), py::arg("aOrientation"));
	cls_StepShape_OrientedFace.def("SetFaceElement", (void (StepShape_OrientedFace::*)(const opencascade::handle<StepShape_Face> &)) &StepShape_OrientedFace::SetFaceElement, "None", py::arg("aFaceElement"));
	cls_StepShape_OrientedFace.def("FaceElement", (opencascade::handle<StepShape_Face> (StepShape_OrientedFace::*)() const ) &StepShape_OrientedFace::FaceElement, "None");
	cls_StepShape_OrientedFace.def("SetOrientation", (void (StepShape_OrientedFace::*)(const Standard_Boolean)) &StepShape_OrientedFace::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_OrientedFace.def("Orientation", (Standard_Boolean (StepShape_OrientedFace::*)() const ) &StepShape_OrientedFace::Orientation, "None");
	cls_StepShape_OrientedFace.def("SetBounds", (void (StepShape_OrientedFace::*)(const opencascade::handle<StepShape_HArray1OfFaceBound> &)) &StepShape_OrientedFace::SetBounds, "None", py::arg("aBounds"));
	cls_StepShape_OrientedFace.def("Bounds", (opencascade::handle<StepShape_HArray1OfFaceBound> (StepShape_OrientedFace::*)() const ) &StepShape_OrientedFace::Bounds, "None");
	cls_StepShape_OrientedFace.def("BoundsValue", (opencascade::handle<StepShape_FaceBound> (StepShape_OrientedFace::*)(const Standard_Integer) const ) &StepShape_OrientedFace::BoundsValue, "None", py::arg("num"));
	cls_StepShape_OrientedFace.def("NbBounds", (Standard_Integer (StepShape_OrientedFace::*)() const ) &StepShape_OrientedFace::NbBounds, "None");
	cls_StepShape_OrientedFace.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedFace::get_type_name, "None");
	cls_StepShape_OrientedFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedFace::get_type_descriptor, "None");
	cls_StepShape_OrientedFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedFace::*)() const ) &StepShape_OrientedFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OrientedOpenShell.hxx
	py::class_<StepShape_OrientedOpenShell, opencascade::handle<StepShape_OrientedOpenShell>, StepShape_OpenShell> cls_StepShape_OrientedOpenShell(mod, "StepShape_OrientedOpenShell", "None");
	cls_StepShape_OrientedOpenShell.def(py::init<>());
	cls_StepShape_OrientedOpenShell.def("Init", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_OpenShell> &, const Standard_Boolean)) &StepShape_OrientedOpenShell::Init, "None", py::arg("aName"), py::arg("aOpenShellElement"), py::arg("aOrientation"));
	cls_StepShape_OrientedOpenShell.def("SetOpenShellElement", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<StepShape_OpenShell> &)) &StepShape_OrientedOpenShell::SetOpenShellElement, "None", py::arg("aOpenShellElement"));
	cls_StepShape_OrientedOpenShell.def("OpenShellElement", (opencascade::handle<StepShape_OpenShell> (StepShape_OrientedOpenShell::*)() const ) &StepShape_OrientedOpenShell::OpenShellElement, "None");
	cls_StepShape_OrientedOpenShell.def("SetOrientation", (void (StepShape_OrientedOpenShell::*)(const Standard_Boolean)) &StepShape_OrientedOpenShell::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_OrientedOpenShell.def("Orientation", (Standard_Boolean (StepShape_OrientedOpenShell::*)() const ) &StepShape_OrientedOpenShell::Orientation, "None");
	cls_StepShape_OrientedOpenShell.def("SetCfsFaces", (void (StepShape_OrientedOpenShell::*)(const opencascade::handle<StepShape_HArray1OfFace> &)) &StepShape_OrientedOpenShell::SetCfsFaces, "None", py::arg("aCfsFaces"));
	cls_StepShape_OrientedOpenShell.def("CfsFaces", (opencascade::handle<StepShape_HArray1OfFace> (StepShape_OrientedOpenShell::*)() const ) &StepShape_OrientedOpenShell::CfsFaces, "None");
	cls_StepShape_OrientedOpenShell.def("CfsFacesValue", (opencascade::handle<StepShape_Face> (StepShape_OrientedOpenShell::*)(const Standard_Integer) const ) &StepShape_OrientedOpenShell::CfsFacesValue, "None", py::arg("num"));
	cls_StepShape_OrientedOpenShell.def("NbCfsFaces", (Standard_Integer (StepShape_OrientedOpenShell::*)() const ) &StepShape_OrientedOpenShell::NbCfsFaces, "None");
	cls_StepShape_OrientedOpenShell.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedOpenShell::get_type_name, "None");
	cls_StepShape_OrientedOpenShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedOpenShell::get_type_descriptor, "None");
	cls_StepShape_OrientedOpenShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedOpenShell::*)() const ) &StepShape_OrientedOpenShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Path.hxx
	py::class_<StepShape_Path, opencascade::handle<StepShape_Path>, StepShape_TopologicalRepresentationItem> cls_StepShape_Path(mod, "StepShape_Path", "None");
	cls_StepShape_Path.def(py::init<>());
	cls_StepShape_Path.def("Init", (void (StepShape_Path::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_Path::Init, "None", py::arg("aName"), py::arg("aEdgeList"));
	cls_StepShape_Path.def("SetEdgeList", (void (StepShape_Path::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_Path::SetEdgeList, "None", py::arg("aEdgeList"));
	cls_StepShape_Path.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_Path::*)() const ) &StepShape_Path::EdgeList, "None");
	cls_StepShape_Path.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_Path::*)(const Standard_Integer) const ) &StepShape_Path::EdgeListValue, "None", py::arg("num"));
	cls_StepShape_Path.def("NbEdgeList", (Standard_Integer (StepShape_Path::*)() const ) &StepShape_Path::NbEdgeList, "None");
	cls_StepShape_Path.def_static("get_type_name_", (const char * (*)()) &StepShape_Path::get_type_name, "None");
	cls_StepShape_Path.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Path::get_type_descriptor, "None");
	cls_StepShape_Path.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Path::*)() const ) &StepShape_Path::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_OrientedPath.hxx
	py::class_<StepShape_OrientedPath, opencascade::handle<StepShape_OrientedPath>, StepShape_Path> cls_StepShape_OrientedPath(mod, "StepShape_OrientedPath", "None");
	cls_StepShape_OrientedPath.def(py::init<>());
	cls_StepShape_OrientedPath.def("Init", (void (StepShape_OrientedPath::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_EdgeLoop> &, const Standard_Boolean)) &StepShape_OrientedPath::Init, "None", py::arg("aName"), py::arg("aPathElement"), py::arg("aOrientation"));
	cls_StepShape_OrientedPath.def("SetPathElement", (void (StepShape_OrientedPath::*)(const opencascade::handle<StepShape_EdgeLoop> &)) &StepShape_OrientedPath::SetPathElement, "None", py::arg("aPathElement"));
	cls_StepShape_OrientedPath.def("PathElement", (opencascade::handle<StepShape_EdgeLoop> (StepShape_OrientedPath::*)() const ) &StepShape_OrientedPath::PathElement, "None");
	cls_StepShape_OrientedPath.def("SetOrientation", (void (StepShape_OrientedPath::*)(const Standard_Boolean)) &StepShape_OrientedPath::SetOrientation, "None", py::arg("aOrientation"));
	cls_StepShape_OrientedPath.def("Orientation", (Standard_Boolean (StepShape_OrientedPath::*)() const ) &StepShape_OrientedPath::Orientation, "None");
	cls_StepShape_OrientedPath.def("SetEdgeList", (void (StepShape_OrientedPath::*)(const opencascade::handle<StepShape_HArray1OfOrientedEdge> &)) &StepShape_OrientedPath::SetEdgeList, "None", py::arg("aEdgeList"));
	cls_StepShape_OrientedPath.def("EdgeList", (opencascade::handle<StepShape_HArray1OfOrientedEdge> (StepShape_OrientedPath::*)() const ) &StepShape_OrientedPath::EdgeList, "None");
	cls_StepShape_OrientedPath.def("EdgeListValue", (opencascade::handle<StepShape_OrientedEdge> (StepShape_OrientedPath::*)(const Standard_Integer) const ) &StepShape_OrientedPath::EdgeListValue, "None", py::arg("num"));
	cls_StepShape_OrientedPath.def("NbEdgeList", (Standard_Integer (StepShape_OrientedPath::*)() const ) &StepShape_OrientedPath::NbEdgeList, "None");
	cls_StepShape_OrientedPath.def_static("get_type_name_", (const char * (*)()) &StepShape_OrientedPath::get_type_name, "None");
	cls_StepShape_OrientedPath.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_OrientedPath::get_type_descriptor, "None");
	cls_StepShape_OrientedPath.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_OrientedPath::*)() const ) &StepShape_OrientedPath::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_PlusMinusTolerance.hxx
	py::class_<StepShape_PlusMinusTolerance, opencascade::handle<StepShape_PlusMinusTolerance>, Standard_Transient> cls_StepShape_PlusMinusTolerance(mod, "StepShape_PlusMinusTolerance", "Added for Dimensional Tolerances");
	cls_StepShape_PlusMinusTolerance.def(py::init<>());
	cls_StepShape_PlusMinusTolerance.def("Init", (void (StepShape_PlusMinusTolerance::*)(const StepShape_ToleranceMethodDefinition &, const StepShape_DimensionalCharacteristic &)) &StepShape_PlusMinusTolerance::Init, "None", py::arg("range"), py::arg("toleranced_dimension"));
	cls_StepShape_PlusMinusTolerance.def("Range", (StepShape_ToleranceMethodDefinition (StepShape_PlusMinusTolerance::*)() const ) &StepShape_PlusMinusTolerance::Range, "None");
	cls_StepShape_PlusMinusTolerance.def("SetRange", (void (StepShape_PlusMinusTolerance::*)(const StepShape_ToleranceMethodDefinition &)) &StepShape_PlusMinusTolerance::SetRange, "None", py::arg("range"));
	cls_StepShape_PlusMinusTolerance.def("TolerancedDimension", (StepShape_DimensionalCharacteristic (StepShape_PlusMinusTolerance::*)() const ) &StepShape_PlusMinusTolerance::TolerancedDimension, "None");
	cls_StepShape_PlusMinusTolerance.def("SetTolerancedDimension", (void (StepShape_PlusMinusTolerance::*)(const StepShape_DimensionalCharacteristic &)) &StepShape_PlusMinusTolerance::SetTolerancedDimension, "None", py::arg("toleranced_dimension"));
	cls_StepShape_PlusMinusTolerance.def_static("get_type_name_", (const char * (*)()) &StepShape_PlusMinusTolerance::get_type_name, "None");
	cls_StepShape_PlusMinusTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PlusMinusTolerance::get_type_descriptor, "None");
	cls_StepShape_PlusMinusTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PlusMinusTolerance::*)() const ) &StepShape_PlusMinusTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_PointRepresentation.hxx
	py::class_<StepShape_PointRepresentation, opencascade::handle<StepShape_PointRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_PointRepresentation(mod, "StepShape_PointRepresentation", "Representation of STEP entity PointRepresentation");
	cls_StepShape_PointRepresentation.def(py::init<>());
	cls_StepShape_PointRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_PointRepresentation::get_type_name, "None");
	cls_StepShape_PointRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PointRepresentation::get_type_descriptor, "None");
	cls_StepShape_PointRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PointRepresentation::*)() const ) &StepShape_PointRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_PolyLoop.hxx
	py::class_<StepShape_PolyLoop, opencascade::handle<StepShape_PolyLoop>, StepShape_Loop> cls_StepShape_PolyLoop(mod, "StepShape_PolyLoop", "None");
	cls_StepShape_PolyLoop.def(py::init<>());
	cls_StepShape_PolyLoop.def("Init", (void (StepShape_PolyLoop::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepShape_PolyLoop::Init, "None", py::arg("aName"), py::arg("aPolygon"));
	cls_StepShape_PolyLoop.def("SetPolygon", (void (StepShape_PolyLoop::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepShape_PolyLoop::SetPolygon, "None", py::arg("aPolygon"));
	cls_StepShape_PolyLoop.def("Polygon", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepShape_PolyLoop::*)() const ) &StepShape_PolyLoop::Polygon, "None");
	cls_StepShape_PolyLoop.def("PolygonValue", (opencascade::handle<StepGeom_CartesianPoint> (StepShape_PolyLoop::*)(const Standard_Integer) const ) &StepShape_PolyLoop::PolygonValue, "None", py::arg("num"));
	cls_StepShape_PolyLoop.def("NbPolygon", (Standard_Integer (StepShape_PolyLoop::*)() const ) &StepShape_PolyLoop::NbPolygon, "None");
	cls_StepShape_PolyLoop.def_static("get_type_name_", (const char * (*)()) &StepShape_PolyLoop::get_type_name, "None");
	cls_StepShape_PolyLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PolyLoop::get_type_descriptor, "None");
	cls_StepShape_PolyLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PolyLoop::*)() const ) &StepShape_PolyLoop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_PrecisionQualifier.hxx
	py::class_<StepShape_PrecisionQualifier, opencascade::handle<StepShape_PrecisionQualifier>, Standard_Transient> cls_StepShape_PrecisionQualifier(mod, "StepShape_PrecisionQualifier", "Added for Dimensional Tolerances");
	cls_StepShape_PrecisionQualifier.def(py::init<>());
	cls_StepShape_PrecisionQualifier.def("Init", (void (StepShape_PrecisionQualifier::*)(const Standard_Integer)) &StepShape_PrecisionQualifier::Init, "None", py::arg("precision_value"));
	cls_StepShape_PrecisionQualifier.def("PrecisionValue", (Standard_Integer (StepShape_PrecisionQualifier::*)() const ) &StepShape_PrecisionQualifier::PrecisionValue, "None");
	cls_StepShape_PrecisionQualifier.def("SetPrecisionValue", (void (StepShape_PrecisionQualifier::*)(const Standard_Integer)) &StepShape_PrecisionQualifier::SetPrecisionValue, "None", py::arg("precision_value"));
	cls_StepShape_PrecisionQualifier.def_static("get_type_name_", (const char * (*)()) &StepShape_PrecisionQualifier::get_type_name, "None");
	cls_StepShape_PrecisionQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PrecisionQualifier::get_type_descriptor, "None");
	cls_StepShape_PrecisionQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PrecisionQualifier::*)() const ) &StepShape_PrecisionQualifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_QualifiedRepresentationItem.hxx
	py::class_<StepShape_QualifiedRepresentationItem, opencascade::handle<StepShape_QualifiedRepresentationItem>, StepRepr_RepresentationItem> cls_StepShape_QualifiedRepresentationItem(mod, "StepShape_QualifiedRepresentationItem", "Added for Dimensional Tolerances");
	cls_StepShape_QualifiedRepresentationItem.def(py::init<>());
	cls_StepShape_QualifiedRepresentationItem.def("Init", (void (StepShape_QualifiedRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_QualifiedRepresentationItem::Init, "None", py::arg("aName"), py::arg("qualifiers"));
	cls_StepShape_QualifiedRepresentationItem.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_QualifiedRepresentationItem::*)() const ) &StepShape_QualifiedRepresentationItem::Qualifiers, "None");
	cls_StepShape_QualifiedRepresentationItem.def("NbQualifiers", (Standard_Integer (StepShape_QualifiedRepresentationItem::*)() const ) &StepShape_QualifiedRepresentationItem::NbQualifiers, "None");
	cls_StepShape_QualifiedRepresentationItem.def("SetQualifiers", (void (StepShape_QualifiedRepresentationItem::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_QualifiedRepresentationItem::SetQualifiers, "None", py::arg("qualifiers"));
	cls_StepShape_QualifiedRepresentationItem.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_QualifiedRepresentationItem::*)(const Standard_Integer) const ) &StepShape_QualifiedRepresentationItem::QualifiersValue, "None", py::arg("num"));
	cls_StepShape_QualifiedRepresentationItem.def("SetQualifiersValue", (void (StepShape_QualifiedRepresentationItem::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_QualifiedRepresentationItem::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
	cls_StepShape_QualifiedRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_QualifiedRepresentationItem::get_type_name, "None");
	cls_StepShape_QualifiedRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_QualifiedRepresentationItem::get_type_descriptor, "None");
	cls_StepShape_QualifiedRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_QualifiedRepresentationItem::*)() const ) &StepShape_QualifiedRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_RevolvedAreaSolid.hxx
	py::class_<StepShape_RevolvedAreaSolid, opencascade::handle<StepShape_RevolvedAreaSolid>, StepShape_SweptAreaSolid> cls_StepShape_RevolvedAreaSolid(mod, "StepShape_RevolvedAreaSolid", "None");
	cls_StepShape_RevolvedAreaSolid.def(py::init<>());
	cls_StepShape_RevolvedAreaSolid.def("Init", (void (StepShape_RevolvedAreaSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real)) &StepShape_RevolvedAreaSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aAxis"), py::arg("aAngle"));
	cls_StepShape_RevolvedAreaSolid.def("SetAxis", (void (StepShape_RevolvedAreaSolid::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RevolvedAreaSolid::SetAxis, "None", py::arg("aAxis"));
	cls_StepShape_RevolvedAreaSolid.def("Axis", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RevolvedAreaSolid::*)() const ) &StepShape_RevolvedAreaSolid::Axis, "None");
	cls_StepShape_RevolvedAreaSolid.def("SetAngle", (void (StepShape_RevolvedAreaSolid::*)(const Standard_Real)) &StepShape_RevolvedAreaSolid::SetAngle, "None", py::arg("aAngle"));
	cls_StepShape_RevolvedAreaSolid.def("Angle", (Standard_Real (StepShape_RevolvedAreaSolid::*)() const ) &StepShape_RevolvedAreaSolid::Angle, "None");
	cls_StepShape_RevolvedAreaSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_RevolvedAreaSolid::get_type_name, "None");
	cls_StepShape_RevolvedAreaSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RevolvedAreaSolid::get_type_descriptor, "None");
	cls_StepShape_RevolvedAreaSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RevolvedAreaSolid::*)() const ) &StepShape_RevolvedAreaSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_RevolvedFaceSolid.hxx
	py::class_<StepShape_RevolvedFaceSolid, opencascade::handle<StepShape_RevolvedFaceSolid>, StepShape_SweptFaceSolid> cls_StepShape_RevolvedFaceSolid(mod, "StepShape_RevolvedFaceSolid", "None");
	cls_StepShape_RevolvedFaceSolid.def(py::init<>());
	cls_StepShape_RevolvedFaceSolid.def("Init", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_RevolvedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"));
	cls_StepShape_RevolvedFaceSolid.def("Init", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real)) &StepShape_RevolvedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aAxis"), py::arg("aAngle"));
	cls_StepShape_RevolvedFaceSolid.def("SetAxis", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RevolvedFaceSolid::SetAxis, "None", py::arg("aAxis"));
	cls_StepShape_RevolvedFaceSolid.def("Axis", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RevolvedFaceSolid::*)() const ) &StepShape_RevolvedFaceSolid::Axis, "None");
	cls_StepShape_RevolvedFaceSolid.def("SetAngle", (void (StepShape_RevolvedFaceSolid::*)(const Standard_Real)) &StepShape_RevolvedFaceSolid::SetAngle, "None", py::arg("aAngle"));
	cls_StepShape_RevolvedFaceSolid.def("Angle", (Standard_Real (StepShape_RevolvedFaceSolid::*)() const ) &StepShape_RevolvedFaceSolid::Angle, "None");
	cls_StepShape_RevolvedFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_RevolvedFaceSolid::get_type_name, "None");
	cls_StepShape_RevolvedFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RevolvedFaceSolid::get_type_descriptor, "None");
	cls_StepShape_RevolvedFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RevolvedFaceSolid::*)() const ) &StepShape_RevolvedFaceSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_RightAngularWedge.hxx
	py::class_<StepShape_RightAngularWedge, opencascade::handle<StepShape_RightAngularWedge>, StepGeom_GeometricRepresentationItem> cls_StepShape_RightAngularWedge(mod, "StepShape_RightAngularWedge", "None");
	cls_StepShape_RightAngularWedge.def(py::init<>());
	cls_StepShape_RightAngularWedge.def("Init", (void (StepShape_RightAngularWedge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_RightAngularWedge::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aX"), py::arg("aY"), py::arg("aZ"), py::arg("aLtx"));
	cls_StepShape_RightAngularWedge.def("SetPosition", (void (StepShape_RightAngularWedge::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepShape_RightAngularWedge::SetPosition, "None", py::arg("aPosition"));
	cls_StepShape_RightAngularWedge.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::Position, "None");
	cls_StepShape_RightAngularWedge.def("SetX", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetX, "None", py::arg("aX"));
	cls_StepShape_RightAngularWedge.def("X", (Standard_Real (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::X, "None");
	cls_StepShape_RightAngularWedge.def("SetY", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetY, "None", py::arg("aY"));
	cls_StepShape_RightAngularWedge.def("Y", (Standard_Real (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::Y, "None");
	cls_StepShape_RightAngularWedge.def("SetZ", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetZ, "None", py::arg("aZ"));
	cls_StepShape_RightAngularWedge.def("Z", (Standard_Real (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::Z, "None");
	cls_StepShape_RightAngularWedge.def("SetLtx", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetLtx, "None", py::arg("aLtx"));
	cls_StepShape_RightAngularWedge.def("Ltx", (Standard_Real (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::Ltx, "None");
	cls_StepShape_RightAngularWedge.def_static("get_type_name_", (const char * (*)()) &StepShape_RightAngularWedge::get_type_name, "None");
	cls_StepShape_RightAngularWedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RightAngularWedge::get_type_descriptor, "None");
	cls_StepShape_RightAngularWedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RightAngularWedge::*)() const ) &StepShape_RightAngularWedge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_RightCircularCone.hxx
	py::class_<StepShape_RightCircularCone, opencascade::handle<StepShape_RightCircularCone>, StepGeom_GeometricRepresentationItem> cls_StepShape_RightCircularCone(mod, "StepShape_RightCircularCone", "None");
	cls_StepShape_RightCircularCone.def(py::init<>());
	cls_StepShape_RightCircularCone.def("Init", (void (StepShape_RightCircularCone::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_RightCircularCone::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aHeight"), py::arg("aRadius"), py::arg("aSemiAngle"));
	cls_StepShape_RightCircularCone.def("SetPosition", (void (StepShape_RightCircularCone::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RightCircularCone::SetPosition, "None", py::arg("aPosition"));
	cls_StepShape_RightCircularCone.def("Position", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RightCircularCone::*)() const ) &StepShape_RightCircularCone::Position, "None");
	cls_StepShape_RightCircularCone.def("SetHeight", (void (StepShape_RightCircularCone::*)(const Standard_Real)) &StepShape_RightCircularCone::SetHeight, "None", py::arg("aHeight"));
	cls_StepShape_RightCircularCone.def("Height", (Standard_Real (StepShape_RightCircularCone::*)() const ) &StepShape_RightCircularCone::Height, "None");
	cls_StepShape_RightCircularCone.def("SetRadius", (void (StepShape_RightCircularCone::*)(const Standard_Real)) &StepShape_RightCircularCone::SetRadius, "None", py::arg("aRadius"));
	cls_StepShape_RightCircularCone.def("Radius", (Standard_Real (StepShape_RightCircularCone::*)() const ) &StepShape_RightCircularCone::Radius, "None");
	cls_StepShape_RightCircularCone.def("SetSemiAngle", (void (StepShape_RightCircularCone::*)(const Standard_Real)) &StepShape_RightCircularCone::SetSemiAngle, "None", py::arg("aSemiAngle"));
	cls_StepShape_RightCircularCone.def("SemiAngle", (Standard_Real (StepShape_RightCircularCone::*)() const ) &StepShape_RightCircularCone::SemiAngle, "None");
	cls_StepShape_RightCircularCone.def_static("get_type_name_", (const char * (*)()) &StepShape_RightCircularCone::get_type_name, "None");
	cls_StepShape_RightCircularCone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RightCircularCone::get_type_descriptor, "None");
	cls_StepShape_RightCircularCone.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RightCircularCone::*)() const ) &StepShape_RightCircularCone::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_RightCircularCylinder.hxx
	py::class_<StepShape_RightCircularCylinder, opencascade::handle<StepShape_RightCircularCylinder>, StepGeom_GeometricRepresentationItem> cls_StepShape_RightCircularCylinder(mod, "StepShape_RightCircularCylinder", "None");
	cls_StepShape_RightCircularCylinder.def(py::init<>());
	cls_StepShape_RightCircularCylinder.def("Init", (void (StepShape_RightCircularCylinder::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real, const Standard_Real)) &StepShape_RightCircularCylinder::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aHeight"), py::arg("aRadius"));
	cls_StepShape_RightCircularCylinder.def("SetPosition", (void (StepShape_RightCircularCylinder::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RightCircularCylinder::SetPosition, "None", py::arg("aPosition"));
	cls_StepShape_RightCircularCylinder.def("Position", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RightCircularCylinder::*)() const ) &StepShape_RightCircularCylinder::Position, "None");
	cls_StepShape_RightCircularCylinder.def("SetHeight", (void (StepShape_RightCircularCylinder::*)(const Standard_Real)) &StepShape_RightCircularCylinder::SetHeight, "None", py::arg("aHeight"));
	cls_StepShape_RightCircularCylinder.def("Height", (Standard_Real (StepShape_RightCircularCylinder::*)() const ) &StepShape_RightCircularCylinder::Height, "None");
	cls_StepShape_RightCircularCylinder.def("SetRadius", (void (StepShape_RightCircularCylinder::*)(const Standard_Real)) &StepShape_RightCircularCylinder::SetRadius, "None", py::arg("aRadius"));
	cls_StepShape_RightCircularCylinder.def("Radius", (Standard_Real (StepShape_RightCircularCylinder::*)() const ) &StepShape_RightCircularCylinder::Radius, "None");
	cls_StepShape_RightCircularCylinder.def_static("get_type_name_", (const char * (*)()) &StepShape_RightCircularCylinder::get_type_name, "None");
	cls_StepShape_RightCircularCylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RightCircularCylinder::get_type_descriptor, "None");
	cls_StepShape_RightCircularCylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RightCircularCylinder::*)() const ) &StepShape_RightCircularCylinder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SeamEdge.hxx
	py::class_<StepShape_SeamEdge, opencascade::handle<StepShape_SeamEdge>, StepShape_OrientedEdge> cls_StepShape_SeamEdge(mod, "StepShape_SeamEdge", "Representation of STEP entity SeamEdge");
	cls_StepShape_SeamEdge.def(py::init<>());
	cls_StepShape_SeamEdge.def("Init", (void (StepShape_SeamEdge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Edge> &, const Standard_Boolean, const opencascade::handle<StepGeom_Pcurve> &)) &StepShape_SeamEdge::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientedEdge_EdgeElement"), py::arg("aOrientedEdge_Orientation"), py::arg("aPcurveReference"));
	cls_StepShape_SeamEdge.def("PcurveReference", (opencascade::handle<StepGeom_Pcurve> (StepShape_SeamEdge::*)() const ) &StepShape_SeamEdge::PcurveReference, "Returns field PcurveReference");
	cls_StepShape_SeamEdge.def("SetPcurveReference", (void (StepShape_SeamEdge::*)(const opencascade::handle<StepGeom_Pcurve> &)) &StepShape_SeamEdge::SetPcurveReference, "Set field PcurveReference", py::arg("PcurveReference"));
	cls_StepShape_SeamEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_SeamEdge::get_type_name, "None");
	cls_StepShape_SeamEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SeamEdge::get_type_descriptor, "None");
	cls_StepShape_SeamEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SeamEdge::*)() const ) &StepShape_SeamEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShapeDefinitionRepresentation.hxx
	py::class_<StepShape_ShapeDefinitionRepresentation, opencascade::handle<StepShape_ShapeDefinitionRepresentation>, StepRepr_PropertyDefinitionRepresentation> cls_StepShape_ShapeDefinitionRepresentation(mod, "StepShape_ShapeDefinitionRepresentation", "Representation of STEP entity ShapeDefinitionRepresentation");
	cls_StepShape_ShapeDefinitionRepresentation.def(py::init<>());
	cls_StepShape_ShapeDefinitionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ShapeDefinitionRepresentation::get_type_name, "None");
	cls_StepShape_ShapeDefinitionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShapeDefinitionRepresentation::get_type_descriptor, "None");
	cls_StepShape_ShapeDefinitionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShapeDefinitionRepresentation::*)() const ) &StepShape_ShapeDefinitionRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShapeDimensionRepresentation.hxx
	py::class_<StepShape_ShapeDimensionRepresentation, opencascade::handle<StepShape_ShapeDimensionRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_ShapeDimensionRepresentation(mod, "StepShape_ShapeDimensionRepresentation", "Representation of STEP entity ShapeDimensionRepresentation");
	cls_StepShape_ShapeDimensionRepresentation.def(py::init<>());
	cls_StepShape_ShapeDimensionRepresentation.def("Init", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepShape_ShapeDimensionRepresentation::Init, "Initialize all fields AP214", py::arg("theName"), py::arg("theItems"), py::arg("theContextOfItems"));
	cls_StepShape_ShapeDimensionRepresentation.def("Init", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepShape_ShapeDimensionRepresentation::Init, "Initialize all fields AP242", py::arg("theName"), py::arg("theItems"), py::arg("theContextOfItems"));
	cls_StepShape_ShapeDimensionRepresentation.def("SetItemsAP242", (void (StepShape_ShapeDimensionRepresentation::*)(const opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> &)) &StepShape_ShapeDimensionRepresentation::SetItemsAP242, "None", py::arg("theItems"));
	cls_StepShape_ShapeDimensionRepresentation.def("ItemsAP242", (opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem> (StepShape_ShapeDimensionRepresentation::*)() const ) &StepShape_ShapeDimensionRepresentation::ItemsAP242, "None");
	cls_StepShape_ShapeDimensionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ShapeDimensionRepresentation::get_type_name, "None");
	cls_StepShape_ShapeDimensionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShapeDimensionRepresentation::get_type_descriptor, "None");
	cls_StepShape_ShapeDimensionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShapeDimensionRepresentation::*)() const ) &StepShape_ShapeDimensionRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_AdvancedBrepShapeRepresentation.hxx
	py::class_<StepShape_AdvancedBrepShapeRepresentation, opencascade::handle<StepShape_AdvancedBrepShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_AdvancedBrepShapeRepresentation(mod, "StepShape_AdvancedBrepShapeRepresentation", "None");
	cls_StepShape_AdvancedBrepShapeRepresentation.def(py::init<>());
	cls_StepShape_AdvancedBrepShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_AdvancedBrepShapeRepresentation::get_type_name, "None");
	cls_StepShape_AdvancedBrepShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_AdvancedBrepShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_AdvancedBrepShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_AdvancedBrepShapeRepresentation::*)() const ) &StepShape_AdvancedBrepShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShapeRepresentationWithParameters.hxx
	py::class_<StepShape_ShapeRepresentationWithParameters, opencascade::handle<StepShape_ShapeRepresentationWithParameters>, StepShape_ShapeRepresentation> cls_StepShape_ShapeRepresentationWithParameters(mod, "StepShape_ShapeRepresentationWithParameters", "Representation of STEP entity ShapeRepresentationWithParameters");
	cls_StepShape_ShapeRepresentationWithParameters.def(py::init<>());
	cls_StepShape_ShapeRepresentationWithParameters.def_static("get_type_name_", (const char * (*)()) &StepShape_ShapeRepresentationWithParameters::get_type_name, "None");
	cls_StepShape_ShapeRepresentationWithParameters.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShapeRepresentationWithParameters::get_type_descriptor, "None");
	cls_StepShape_ShapeRepresentationWithParameters.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShapeRepresentationWithParameters::*)() const ) &StepShape_ShapeRepresentationWithParameters::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShellBasedSurfaceModel.hxx
	py::class_<StepShape_ShellBasedSurfaceModel, opencascade::handle<StepShape_ShellBasedSurfaceModel>, StepGeom_GeometricRepresentationItem> cls_StepShape_ShellBasedSurfaceModel(mod, "StepShape_ShellBasedSurfaceModel", "None");
	cls_StepShape_ShellBasedSurfaceModel.def(py::init<>());
	cls_StepShape_ShellBasedSurfaceModel.def("Init", (void (StepShape_ShellBasedSurfaceModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfShell> &)) &StepShape_ShellBasedSurfaceModel::Init, "None", py::arg("aName"), py::arg("aSbsmBoundary"));
	cls_StepShape_ShellBasedSurfaceModel.def("SetSbsmBoundary", (void (StepShape_ShellBasedSurfaceModel::*)(const opencascade::handle<StepShape_HArray1OfShell> &)) &StepShape_ShellBasedSurfaceModel::SetSbsmBoundary, "None", py::arg("aSbsmBoundary"));
	cls_StepShape_ShellBasedSurfaceModel.def("SbsmBoundary", (opencascade::handle<StepShape_HArray1OfShell> (StepShape_ShellBasedSurfaceModel::*)() const ) &StepShape_ShellBasedSurfaceModel::SbsmBoundary, "None");
	cls_StepShape_ShellBasedSurfaceModel.def("SbsmBoundaryValue", (StepShape_Shell (StepShape_ShellBasedSurfaceModel::*)(const Standard_Integer) const ) &StepShape_ShellBasedSurfaceModel::SbsmBoundaryValue, "None", py::arg("num"));
	cls_StepShape_ShellBasedSurfaceModel.def("NbSbsmBoundary", (Standard_Integer (StepShape_ShellBasedSurfaceModel::*)() const ) &StepShape_ShellBasedSurfaceModel::NbSbsmBoundary, "None");
	cls_StepShape_ShellBasedSurfaceModel.def_static("get_type_name_", (const char * (*)()) &StepShape_ShellBasedSurfaceModel::get_type_name, "None");
	cls_StepShape_ShellBasedSurfaceModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ShellBasedSurfaceModel::get_type_descriptor, "None");
	cls_StepShape_ShellBasedSurfaceModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ShellBasedSurfaceModel::*)() const ) &StepShape_ShellBasedSurfaceModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_FacetedBrep.hxx
	py::class_<StepShape_FacetedBrep, opencascade::handle<StepShape_FacetedBrep>, StepShape_ManifoldSolidBrep> cls_StepShape_FacetedBrep(mod, "StepShape_FacetedBrep", "None");
	cls_StepShape_FacetedBrep.def(py::init<>());
	cls_StepShape_FacetedBrep.def_static("get_type_name_", (const char * (*)()) &StepShape_FacetedBrep::get_type_name, "None");
	cls_StepShape_FacetedBrep.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_FacetedBrep::get_type_descriptor, "None");
	cls_StepShape_FacetedBrep.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_FacetedBrep::*)() const ) &StepShape_FacetedBrep::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SolidReplica.hxx
	py::class_<StepShape_SolidReplica, opencascade::handle<StepShape_SolidReplica>, StepShape_SolidModel> cls_StepShape_SolidReplica(mod, "StepShape_SolidReplica", "None");
	cls_StepShape_SolidReplica.def(py::init<>());
	cls_StepShape_SolidReplica.def("Init", (void (StepShape_SolidReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_SolidModel> &, const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepShape_SolidReplica::Init, "None", py::arg("aName"), py::arg("aParentSolid"), py::arg("aTransformation"));
	cls_StepShape_SolidReplica.def("SetParentSolid", (void (StepShape_SolidReplica::*)(const opencascade::handle<StepShape_SolidModel> &)) &StepShape_SolidReplica::SetParentSolid, "None", py::arg("aParentSolid"));
	cls_StepShape_SolidReplica.def("ParentSolid", (opencascade::handle<StepShape_SolidModel> (StepShape_SolidReplica::*)() const ) &StepShape_SolidReplica::ParentSolid, "None");
	cls_StepShape_SolidReplica.def("SetTransformation", (void (StepShape_SolidReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepShape_SolidReplica::SetTransformation, "None", py::arg("aTransformation"));
	cls_StepShape_SolidReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator3d> (StepShape_SolidReplica::*)() const ) &StepShape_SolidReplica::Transformation, "None");
	cls_StepShape_SolidReplica.def_static("get_type_name_", (const char * (*)()) &StepShape_SolidReplica::get_type_name, "None");
	cls_StepShape_SolidReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SolidReplica::get_type_descriptor, "None");
	cls_StepShape_SolidReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SolidReplica::*)() const ) &StepShape_SolidReplica::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Sphere.hxx
	py::class_<StepShape_Sphere, opencascade::handle<StepShape_Sphere>, StepGeom_GeometricRepresentationItem> cls_StepShape_Sphere(mod, "StepShape_Sphere", "None");
	cls_StepShape_Sphere.def(py::init<>());
	cls_StepShape_Sphere.def("Init", (void (StepShape_Sphere::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<StepGeom_Point> &)) &StepShape_Sphere::Init, "None", py::arg("aName"), py::arg("aRadius"), py::arg("aCentre"));
	cls_StepShape_Sphere.def("SetRadius", (void (StepShape_Sphere::*)(const Standard_Real)) &StepShape_Sphere::SetRadius, "None", py::arg("aRadius"));
	cls_StepShape_Sphere.def("Radius", (Standard_Real (StepShape_Sphere::*)() const ) &StepShape_Sphere::Radius, "None");
	cls_StepShape_Sphere.def("SetCentre", (void (StepShape_Sphere::*)(const opencascade::handle<StepGeom_Point> &)) &StepShape_Sphere::SetCentre, "None", py::arg("aCentre"));
	cls_StepShape_Sphere.def("Centre", (opencascade::handle<StepGeom_Point> (StepShape_Sphere::*)() const ) &StepShape_Sphere::Centre, "None");
	cls_StepShape_Sphere.def_static("get_type_name_", (const char * (*)()) &StepShape_Sphere::get_type_name, "None");
	cls_StepShape_Sphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Sphere::get_type_descriptor, "None");
	cls_StepShape_Sphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Sphere::*)() const ) &StepShape_Sphere::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Subedge.hxx
	py::class_<StepShape_Subedge, opencascade::handle<StepShape_Subedge>, StepShape_Edge> cls_StepShape_Subedge(mod, "StepShape_Subedge", "Representation of STEP entity Subedge");
	cls_StepShape_Subedge.def(py::init<>());
	cls_StepShape_Subedge.def("Init", (void (StepShape_Subedge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Vertex> &, const opencascade::handle<StepShape_Edge> &)) &StepShape_Subedge::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aEdge_EdgeStart"), py::arg("aEdge_EdgeEnd"), py::arg("aParentEdge"));
	cls_StepShape_Subedge.def("ParentEdge", (opencascade::handle<StepShape_Edge> (StepShape_Subedge::*)() const ) &StepShape_Subedge::ParentEdge, "Returns field ParentEdge");
	cls_StepShape_Subedge.def("SetParentEdge", (void (StepShape_Subedge::*)(const opencascade::handle<StepShape_Edge> &)) &StepShape_Subedge::SetParentEdge, "Set field ParentEdge", py::arg("ParentEdge"));
	cls_StepShape_Subedge.def_static("get_type_name_", (const char * (*)()) &StepShape_Subedge::get_type_name, "None");
	cls_StepShape_Subedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Subedge::get_type_descriptor, "None");
	cls_StepShape_Subedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Subedge::*)() const ) &StepShape_Subedge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Subface.hxx
	py::class_<StepShape_Subface, opencascade::handle<StepShape_Subface>, StepShape_Face> cls_StepShape_Subface(mod, "StepShape_Subface", "Representation of STEP entity Subface");
	cls_StepShape_Subface.def(py::init<>());
	cls_StepShape_Subface.def("Init", (void (StepShape_Subface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_HArray1OfFaceBound> &, const opencascade::handle<StepShape_Face> &)) &StepShape_Subface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFace_Bounds"), py::arg("aParentFace"));
	cls_StepShape_Subface.def("ParentFace", (opencascade::handle<StepShape_Face> (StepShape_Subface::*)() const ) &StepShape_Subface::ParentFace, "Returns field ParentFace");
	cls_StepShape_Subface.def("SetParentFace", (void (StepShape_Subface::*)(const opencascade::handle<StepShape_Face> &)) &StepShape_Subface::SetParentFace, "Set field ParentFace", py::arg("ParentFace"));
	cls_StepShape_Subface.def_static("get_type_name_", (const char * (*)()) &StepShape_Subface::get_type_name, "None");
	cls_StepShape_Subface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Subface::get_type_descriptor, "None");
	cls_StepShape_Subface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Subface::*)() const ) &StepShape_Subface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ExtrudedAreaSolid.hxx
	py::class_<StepShape_ExtrudedAreaSolid, opencascade::handle<StepShape_ExtrudedAreaSolid>, StepShape_SweptAreaSolid> cls_StepShape_ExtrudedAreaSolid(mod, "StepShape_ExtrudedAreaSolid", "None");
	cls_StepShape_ExtrudedAreaSolid.def(py::init<>());
	cls_StepShape_ExtrudedAreaSolid.def("Init", (void (StepShape_ExtrudedAreaSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepShape_ExtrudedAreaSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aExtrudedDirection"), py::arg("aDepth"));
	cls_StepShape_ExtrudedAreaSolid.def("SetExtrudedDirection", (void (StepShape_ExtrudedAreaSolid::*)(const opencascade::handle<StepGeom_Direction> &)) &StepShape_ExtrudedAreaSolid::SetExtrudedDirection, "None", py::arg("aExtrudedDirection"));
	cls_StepShape_ExtrudedAreaSolid.def("ExtrudedDirection", (opencascade::handle<StepGeom_Direction> (StepShape_ExtrudedAreaSolid::*)() const ) &StepShape_ExtrudedAreaSolid::ExtrudedDirection, "None");
	cls_StepShape_ExtrudedAreaSolid.def("SetDepth", (void (StepShape_ExtrudedAreaSolid::*)(const Standard_Real)) &StepShape_ExtrudedAreaSolid::SetDepth, "None", py::arg("aDepth"));
	cls_StepShape_ExtrudedAreaSolid.def("Depth", (Standard_Real (StepShape_ExtrudedAreaSolid::*)() const ) &StepShape_ExtrudedAreaSolid::Depth, "None");
	cls_StepShape_ExtrudedAreaSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_ExtrudedAreaSolid::get_type_name, "None");
	cls_StepShape_ExtrudedAreaSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ExtrudedAreaSolid::get_type_descriptor, "None");
	cls_StepShape_ExtrudedAreaSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ExtrudedAreaSolid::*)() const ) &StepShape_ExtrudedAreaSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ExtrudedFaceSolid.hxx
	py::class_<StepShape_ExtrudedFaceSolid, opencascade::handle<StepShape_ExtrudedFaceSolid>, StepShape_SweptFaceSolid> cls_StepShape_ExtrudedFaceSolid(mod, "StepShape_ExtrudedFaceSolid", "None");
	cls_StepShape_ExtrudedFaceSolid.def(py::init<>());
	cls_StepShape_ExtrudedFaceSolid.def("Init", (void (StepShape_ExtrudedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepShape_ExtrudedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aExtrudedDirection"), py::arg("aDepth"));
	cls_StepShape_ExtrudedFaceSolid.def("SetExtrudedDirection", (void (StepShape_ExtrudedFaceSolid::*)(const opencascade::handle<StepGeom_Direction> &)) &StepShape_ExtrudedFaceSolid::SetExtrudedDirection, "None", py::arg("aExtrudedDirection"));
	cls_StepShape_ExtrudedFaceSolid.def("ExtrudedDirection", (opencascade::handle<StepGeom_Direction> (StepShape_ExtrudedFaceSolid::*)() const ) &StepShape_ExtrudedFaceSolid::ExtrudedDirection, "None");
	cls_StepShape_ExtrudedFaceSolid.def("SetDepth", (void (StepShape_ExtrudedFaceSolid::*)(const Standard_Real)) &StepShape_ExtrudedFaceSolid::SetDepth, "None", py::arg("aDepth"));
	cls_StepShape_ExtrudedFaceSolid.def("Depth", (Standard_Real (StepShape_ExtrudedFaceSolid::*)() const ) &StepShape_ExtrudedFaceSolid::Depth, "None");
	cls_StepShape_ExtrudedFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_ExtrudedFaceSolid::get_type_name, "None");
	cls_StepShape_ExtrudedFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ExtrudedFaceSolid::get_type_descriptor, "None");
	cls_StepShape_ExtrudedFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ExtrudedFaceSolid::*)() const ) &StepShape_ExtrudedFaceSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ToleranceValue.hxx
	py::class_<StepShape_ToleranceValue, opencascade::handle<StepShape_ToleranceValue>, Standard_Transient> cls_StepShape_ToleranceValue(mod, "StepShape_ToleranceValue", "Added for Dimensional Tolerances");
	cls_StepShape_ToleranceValue.def(py::init<>());
	cls_StepShape_ToleranceValue.def("Init", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::Init, "None", py::arg("lower_bound"), py::arg("upper_bound"));
	cls_StepShape_ToleranceValue.def("LowerBound", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_ToleranceValue::*)() const ) &StepShape_ToleranceValue::LowerBound, "None");
	cls_StepShape_ToleranceValue.def("SetLowerBound", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::SetLowerBound, "None", py::arg("lower_bound"));
	cls_StepShape_ToleranceValue.def("UpperBound", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_ToleranceValue::*)() const ) &StepShape_ToleranceValue::UpperBound, "None");
	cls_StepShape_ToleranceValue.def("SetUpperBound", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::SetUpperBound, "None", py::arg("upper_bound"));
	cls_StepShape_ToleranceValue.def_static("get_type_name_", (const char * (*)()) &StepShape_ToleranceValue::get_type_name, "None");
	cls_StepShape_ToleranceValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ToleranceValue::get_type_descriptor, "None");
	cls_StepShape_ToleranceValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ToleranceValue::*)() const ) &StepShape_ToleranceValue::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_AdvancedFace.hxx
	py::class_<StepShape_AdvancedFace, opencascade::handle<StepShape_AdvancedFace>, StepShape_FaceSurface> cls_StepShape_AdvancedFace(mod, "StepShape_AdvancedFace", "None");
	cls_StepShape_AdvancedFace.def(py::init<>());
	cls_StepShape_AdvancedFace.def_static("get_type_name_", (const char * (*)()) &StepShape_AdvancedFace::get_type_name, "None");
	cls_StepShape_AdvancedFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_AdvancedFace::get_type_descriptor, "None");
	cls_StepShape_AdvancedFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_AdvancedFace::*)() const ) &StepShape_AdvancedFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Torus.hxx
	py::class_<StepShape_Torus, opencascade::handle<StepShape_Torus>, StepGeom_GeometricRepresentationItem> cls_StepShape_Torus(mod, "StepShape_Torus", "None");
	cls_StepShape_Torus.def(py::init<>());
	cls_StepShape_Torus.def("Init", (void (StepShape_Torus::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real, const Standard_Real)) &StepShape_Torus::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aMajorRadius"), py::arg("aMinorRadius"));
	cls_StepShape_Torus.def("SetPosition", (void (StepShape_Torus::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_Torus::SetPosition, "None", py::arg("aPosition"));
	cls_StepShape_Torus.def("Position", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_Torus::*)() const ) &StepShape_Torus::Position, "None");
	cls_StepShape_Torus.def("SetMajorRadius", (void (StepShape_Torus::*)(const Standard_Real)) &StepShape_Torus::SetMajorRadius, "None", py::arg("aMajorRadius"));
	cls_StepShape_Torus.def("MajorRadius", (Standard_Real (StepShape_Torus::*)() const ) &StepShape_Torus::MajorRadius, "None");
	cls_StepShape_Torus.def("SetMinorRadius", (void (StepShape_Torus::*)(const Standard_Real)) &StepShape_Torus::SetMinorRadius, "None", py::arg("aMinorRadius"));
	cls_StepShape_Torus.def("MinorRadius", (Standard_Real (StepShape_Torus::*)() const ) &StepShape_Torus::MinorRadius, "None");
	cls_StepShape_Torus.def_static("get_type_name_", (const char * (*)()) &StepShape_Torus::get_type_name, "None");
	cls_StepShape_Torus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Torus::get_type_descriptor, "None");
	cls_StepShape_Torus.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Torus::*)() const ) &StepShape_Torus::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_TransitionalShapeRepresentation.hxx
	py::class_<StepShape_TransitionalShapeRepresentation, opencascade::handle<StepShape_TransitionalShapeRepresentation>, StepShape_ShapeRepresentation> cls_StepShape_TransitionalShapeRepresentation(mod, "StepShape_TransitionalShapeRepresentation", "None");
	cls_StepShape_TransitionalShapeRepresentation.def(py::init<>());
	cls_StepShape_TransitionalShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_TransitionalShapeRepresentation::get_type_name, "None");
	cls_StepShape_TransitionalShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_TransitionalShapeRepresentation::get_type_descriptor, "None");
	cls_StepShape_TransitionalShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_TransitionalShapeRepresentation::*)() const ) &StepShape_TransitionalShapeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_TypeQualifier.hxx
	py::class_<StepShape_TypeQualifier, opencascade::handle<StepShape_TypeQualifier>, Standard_Transient> cls_StepShape_TypeQualifier(mod, "StepShape_TypeQualifier", "Added for Dimensional Tolerances");
	cls_StepShape_TypeQualifier.def(py::init<>());
	cls_StepShape_TypeQualifier.def("Init", (void (StepShape_TypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_TypeQualifier::Init, "None", py::arg("name"));
	cls_StepShape_TypeQualifier.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_TypeQualifier::*)() const ) &StepShape_TypeQualifier::Name, "None");
	cls_StepShape_TypeQualifier.def("SetName", (void (StepShape_TypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_TypeQualifier::SetName, "None", py::arg("name"));
	cls_StepShape_TypeQualifier.def_static("get_type_name_", (const char * (*)()) &StepShape_TypeQualifier::get_type_name, "None");
	cls_StepShape_TypeQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_TypeQualifier::get_type_descriptor, "None");
	cls_StepShape_TypeQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_TypeQualifier::*)() const ) &StepShape_TypeQualifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ValueFormatTypeQualifier.hxx
	py::class_<StepShape_ValueFormatTypeQualifier, opencascade::handle<StepShape_ValueFormatTypeQualifier>, Standard_Transient> cls_StepShape_ValueFormatTypeQualifier(mod, "StepShape_ValueFormatTypeQualifier", "Added for Dimensional Tolerances");
	cls_StepShape_ValueFormatTypeQualifier.def(py::init<>());
	cls_StepShape_ValueFormatTypeQualifier.def("Init", (void (StepShape_ValueFormatTypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_ValueFormatTypeQualifier::Init, "Init all field own and inherited", py::arg("theFormatType"));
	cls_StepShape_ValueFormatTypeQualifier.def("FormatType", (opencascade::handle<TCollection_HAsciiString> (StepShape_ValueFormatTypeQualifier::*)()) &StepShape_ValueFormatTypeQualifier::FormatType, "Returns field FormatType");
	cls_StepShape_ValueFormatTypeQualifier.def("SetFormatType", (void (StepShape_ValueFormatTypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_ValueFormatTypeQualifier::SetFormatType, "Set field FormatType", py::arg("theFormatType"));
	cls_StepShape_ValueFormatTypeQualifier.def_static("get_type_name_", (const char * (*)()) &StepShape_ValueFormatTypeQualifier::get_type_name, "None");
	cls_StepShape_ValueFormatTypeQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ValueFormatTypeQualifier::get_type_descriptor, "None");
	cls_StepShape_ValueFormatTypeQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ValueFormatTypeQualifier::*)() const ) &StepShape_ValueFormatTypeQualifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Vertex.hxx
	py::class_<StepShape_Vertex, opencascade::handle<StepShape_Vertex>, StepShape_TopologicalRepresentationItem> cls_StepShape_Vertex(mod, "StepShape_Vertex", "None");
	cls_StepShape_Vertex.def(py::init<>());
	cls_StepShape_Vertex.def_static("get_type_name_", (const char * (*)()) &StepShape_Vertex::get_type_name, "None");
	cls_StepShape_Vertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Vertex::get_type_descriptor, "None");
	cls_StepShape_Vertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Vertex::*)() const ) &StepShape_Vertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_VertexLoop.hxx
	py::class_<StepShape_VertexLoop, opencascade::handle<StepShape_VertexLoop>, StepShape_Loop> cls_StepShape_VertexLoop(mod, "StepShape_VertexLoop", "None");
	cls_StepShape_VertexLoop.def(py::init<>());
	cls_StepShape_VertexLoop.def("Init", (void (StepShape_VertexLoop::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_Vertex> &)) &StepShape_VertexLoop::Init, "None", py::arg("aName"), py::arg("aLoopVertex"));
	cls_StepShape_VertexLoop.def("SetLoopVertex", (void (StepShape_VertexLoop::*)(const opencascade::handle<StepShape_Vertex> &)) &StepShape_VertexLoop::SetLoopVertex, "None", py::arg("aLoopVertex"));
	cls_StepShape_VertexLoop.def("LoopVertex", (opencascade::handle<StepShape_Vertex> (StepShape_VertexLoop::*)() const ) &StepShape_VertexLoop::LoopVertex, "None");
	cls_StepShape_VertexLoop.def_static("get_type_name_", (const char * (*)()) &StepShape_VertexLoop::get_type_name, "None");
	cls_StepShape_VertexLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_VertexLoop::get_type_descriptor, "None");
	cls_StepShape_VertexLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_VertexLoop::*)() const ) &StepShape_VertexLoop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_VertexPoint.hxx
	py::class_<StepShape_VertexPoint, opencascade::handle<StepShape_VertexPoint>, StepShape_Vertex> cls_StepShape_VertexPoint(mod, "StepShape_VertexPoint", "None");
	cls_StepShape_VertexPoint.def(py::init<>());
	cls_StepShape_VertexPoint.def("Init", (void (StepShape_VertexPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Point> &)) &StepShape_VertexPoint::Init, "None", py::arg("aName"), py::arg("aVertexGeometry"));
	cls_StepShape_VertexPoint.def("SetVertexGeometry", (void (StepShape_VertexPoint::*)(const opencascade::handle<StepGeom_Point> &)) &StepShape_VertexPoint::SetVertexGeometry, "None", py::arg("aVertexGeometry"));
	cls_StepShape_VertexPoint.def("VertexGeometry", (opencascade::handle<StepGeom_Point> (StepShape_VertexPoint::*)() const ) &StepShape_VertexPoint::VertexGeometry, "None");
	cls_StepShape_VertexPoint.def_static("get_type_name_", (const char * (*)()) &StepShape_VertexPoint::get_type_name, "None");
	cls_StepShape_VertexPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_VertexPoint::get_type_descriptor, "None");
	cls_StepShape_VertexPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_VertexPoint::*)() const ) &StepShape_VertexPoint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfFaceBound.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_FaceBound> >(mod, "StepShape_Array1OfFaceBound");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfEdge.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_Edge> >(mod, "StepShape_Array1OfEdge");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfFace.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_Face> >(mod, "StepShape_Array1OfFace");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_GeometricSetSelect.hxx
	py::class_<StepShape_GeometricSetSelect, std::unique_ptr<StepShape_GeometricSetSelect, Deleter<StepShape_GeometricSetSelect>>, StepData_SelectType> cls_StepShape_GeometricSetSelect(mod, "StepShape_GeometricSetSelect", "None");
	cls_StepShape_GeometricSetSelect.def(py::init<>());
	cls_StepShape_GeometricSetSelect.def("CaseNum", (Standard_Integer (StepShape_GeometricSetSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_GeometricSetSelect::CaseNum, "Recognizes a GeometricSetSelect Kind Entity that is : 1 -> Point 2 -> Curve 3 -> Surface 0 else", py::arg("ent"));
	cls_StepShape_GeometricSetSelect.def("Point", (opencascade::handle<StepGeom_Point> (StepShape_GeometricSetSelect::*)() const ) &StepShape_GeometricSetSelect::Point, "returns Value as a Point (Null if another type)");
	cls_StepShape_GeometricSetSelect.def("Curve", (opencascade::handle<StepGeom_Curve> (StepShape_GeometricSetSelect::*)() const ) &StepShape_GeometricSetSelect::Curve, "returns Value as a Curve (Null if another type)");
	cls_StepShape_GeometricSetSelect.def("Surface", (opencascade::handle<StepGeom_Surface> (StepShape_GeometricSetSelect::*)() const ) &StepShape_GeometricSetSelect::Surface, "returns Value as a Surface (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ShapeDimensionRepresentationItem.hxx
	py::class_<StepShape_ShapeDimensionRepresentationItem, std::unique_ptr<StepShape_ShapeDimensionRepresentationItem, Deleter<StepShape_ShapeDimensionRepresentationItem>>, StepData_SelectType> cls_StepShape_ShapeDimensionRepresentationItem(mod, "StepShape_ShapeDimensionRepresentationItem", "None");
	cls_StepShape_ShapeDimensionRepresentationItem.def(py::init<>());
	cls_StepShape_ShapeDimensionRepresentationItem.def("CaseNum", (Standard_Integer (StepShape_ShapeDimensionRepresentationItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_ShapeDimensionRepresentationItem::CaseNum, "Recognizes a ShapeDimensionRepresentationItem Kind Entity that is : 1 -> CompoundRepresentationItem 2 -> DescriptiveRepresentationItem 3 -> MeasureRepresentationItem 4 -> Placement 0 else", py::arg("ent"));
	cls_StepShape_ShapeDimensionRepresentationItem.def("CompoundRepresentationItem", (opencascade::handle<StepRepr_CompoundRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const ) &StepShape_ShapeDimensionRepresentationItem::CompoundRepresentationItem, "returns Value as a CompoundRepresentationItem (Null if another type)");
	cls_StepShape_ShapeDimensionRepresentationItem.def("DescriptiveRepresentationItem", (opencascade::handle<StepRepr_DescriptiveRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const ) &StepShape_ShapeDimensionRepresentationItem::DescriptiveRepresentationItem, "returns Value as a DescriptiveRepresentationItem (Null if another type)");
	cls_StepShape_ShapeDimensionRepresentationItem.def("MeasureRepresentationItem", (opencascade::handle<StepRepr_MeasureRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const ) &StepShape_ShapeDimensionRepresentationItem::MeasureRepresentationItem, "returns Value as a MeasureRepresentationItem (Null if another type)");
	cls_StepShape_ShapeDimensionRepresentationItem.def("Placement", (opencascade::handle<StepGeom_Placement> (StepShape_ShapeDimensionRepresentationItem::*)() const ) &StepShape_ShapeDimensionRepresentationItem::Placement, "returns Value as a Placement (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Shell.hxx
	py::class_<StepShape_Shell, std::unique_ptr<StepShape_Shell, Deleter<StepShape_Shell>>, StepData_SelectType> cls_StepShape_Shell(mod, "StepShape_Shell", "None");
	cls_StepShape_Shell.def(py::init<>());
	cls_StepShape_Shell.def("CaseNum", (Standard_Integer (StepShape_Shell::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_Shell::CaseNum, "Recognizes a Shell Kind Entity that is : 1 -> OpenShell 2 -> ClosedShell 0 else", py::arg("ent"));
	cls_StepShape_Shell.def("OpenShell", (opencascade::handle<StepShape_OpenShell> (StepShape_Shell::*)() const ) &StepShape_Shell::OpenShell, "returns Value as a OpenShell (Null if another type)");
	cls_StepShape_Shell.def("ClosedShell", (opencascade::handle<StepShape_ClosedShell> (StepShape_Shell::*)() const ) &StepShape_Shell::ClosedShell, "returns Value as a ClosedShell (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ValueQualifier.hxx
	py::class_<StepShape_ValueQualifier, std::unique_ptr<StepShape_ValueQualifier, Deleter<StepShape_ValueQualifier>>, StepData_SelectType> cls_StepShape_ValueQualifier(mod, "StepShape_ValueQualifier", "Added for Dimensional Tolerances");
	cls_StepShape_ValueQualifier.def(py::init<>());
	cls_StepShape_ValueQualifier.def("CaseNum", (Standard_Integer (StepShape_ValueQualifier::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_ValueQualifier::CaseNum, "Recognizes a kind of ValueQualifier Select Type : 1 -> PrecisionQualifier from StepShape 2 -> TypeQualifier from StepShape 3 -> UnceraintyQualifier .. not yet implemented 4 -> ValueFormatTypeQualifier", py::arg("ent"));
	cls_StepShape_ValueQualifier.def("PrecisionQualifier", (opencascade::handle<StepShape_PrecisionQualifier> (StepShape_ValueQualifier::*)() const ) &StepShape_ValueQualifier::PrecisionQualifier, "Returns Value as PrecisionQualifier");
	cls_StepShape_ValueQualifier.def("TypeQualifier", (opencascade::handle<StepShape_TypeQualifier> (StepShape_ValueQualifier::*)() const ) &StepShape_ValueQualifier::TypeQualifier, "Returns Value as TypeQualifier");
	cls_StepShape_ValueQualifier.def("ValueFormatTypeQualifier", (opencascade::handle<StepShape_ValueFormatTypeQualifier> (StepShape_ValueQualifier::*)() const ) &StepShape_ValueQualifier::ValueFormatTypeQualifier, "Returns Value as ValueFormatTypeQualifier");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_CsgPrimitive.hxx
	py::class_<StepShape_CsgPrimitive, std::unique_ptr<StepShape_CsgPrimitive, Deleter<StepShape_CsgPrimitive>>, StepData_SelectType> cls_StepShape_CsgPrimitive(mod, "StepShape_CsgPrimitive", "None");
	cls_StepShape_CsgPrimitive.def(py::init<>());
	cls_StepShape_CsgPrimitive.def("CaseNum", (Standard_Integer (StepShape_CsgPrimitive::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_CsgPrimitive::CaseNum, "Recognizes a CsgPrimitive Kind Entity that is : 1 -> Sphere 2 -> Block 3 -> RightAngularWedge 4 -> Torus 5 -> RightCircularCone 6 -> RightCircularCylinder 0 else", py::arg("ent"));
	cls_StepShape_CsgPrimitive.def("Sphere", (opencascade::handle<StepShape_Sphere> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::Sphere, "returns Value as a Sphere (Null if another type)");
	cls_StepShape_CsgPrimitive.def("Block", (opencascade::handle<StepShape_Block> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::Block, "returns Value as a Block (Null if another type)");
	cls_StepShape_CsgPrimitive.def("RightAngularWedge", (opencascade::handle<StepShape_RightAngularWedge> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::RightAngularWedge, "returns Value as a RightAngularWedge (Null if another type)");
	cls_StepShape_CsgPrimitive.def("Torus", (opencascade::handle<StepShape_Torus> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::Torus, "returns Value as a Torus (Null if another type)");
	cls_StepShape_CsgPrimitive.def("RightCircularCone", (opencascade::handle<StepShape_RightCircularCone> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::RightCircularCone, "returns Value as a RightCircularCone (Null if another type)");
	cls_StepShape_CsgPrimitive.def("RightCircularCylinder", (opencascade::handle<StepShape_RightCircularCylinder> (StepShape_CsgPrimitive::*)() const ) &StepShape_CsgPrimitive::RightCircularCylinder, "returns Value as a RightCircularCylinder (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_BooleanOperand.hxx
	py::class_<StepShape_BooleanOperand, std::unique_ptr<StepShape_BooleanOperand, Deleter<StepShape_BooleanOperand>>> cls_StepShape_BooleanOperand(mod, "StepShape_BooleanOperand", "None");
	cls_StepShape_BooleanOperand.def(py::init<>());
	cls_StepShape_BooleanOperand.def("SetTypeOfContent", (void (StepShape_BooleanOperand::*)(const Standard_Integer)) &StepShape_BooleanOperand::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
	cls_StepShape_BooleanOperand.def("TypeOfContent", (Standard_Integer (StepShape_BooleanOperand::*)() const ) &StepShape_BooleanOperand::TypeOfContent, "None");
	cls_StepShape_BooleanOperand.def("SolidModel", (opencascade::handle<StepShape_SolidModel> (StepShape_BooleanOperand::*)() const ) &StepShape_BooleanOperand::SolidModel, "returns Value as a SolidModel (Null if another type)");
	cls_StepShape_BooleanOperand.def("SetSolidModel", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_SolidModel> &)) &StepShape_BooleanOperand::SetSolidModel, "None", py::arg("aSolidModel"));
	cls_StepShape_BooleanOperand.def("HalfSpaceSolid", (opencascade::handle<StepShape_HalfSpaceSolid> (StepShape_BooleanOperand::*)() const ) &StepShape_BooleanOperand::HalfSpaceSolid, "returns Value as a HalfSpaceSolid (Null if another type)");
	cls_StepShape_BooleanOperand.def("SetHalfSpaceSolid", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_HalfSpaceSolid> &)) &StepShape_BooleanOperand::SetHalfSpaceSolid, "None", py::arg("aHalfSpaceSolid"));
	cls_StepShape_BooleanOperand.def("CsgPrimitive", (StepShape_CsgPrimitive (StepShape_BooleanOperand::*)() const ) &StepShape_BooleanOperand::CsgPrimitive, "returns Value as a CsgPrimitive (Null if another type) CsgPrimitive is another Select Type");
	cls_StepShape_BooleanOperand.def("SetCsgPrimitive", (void (StepShape_BooleanOperand::*)(const StepShape_CsgPrimitive &)) &StepShape_BooleanOperand::SetCsgPrimitive, "None", py::arg("aCsgPrimitive"));
	cls_StepShape_BooleanOperand.def("BooleanResult", (opencascade::handle<StepShape_BooleanResult> (StepShape_BooleanOperand::*)() const ) &StepShape_BooleanOperand::BooleanResult, "returns Value as a BooleanResult (Null if another type)");
	cls_StepShape_BooleanOperand.def("SetBooleanResult", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_BooleanResult> &)) &StepShape_BooleanOperand::SetBooleanResult, "None", py::arg("aBooleanResult"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfOrientedClosedShell.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_OrientedClosedShell> >(mod, "StepShape_Array1OfOrientedClosedShell");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_CsgSelect.hxx
	py::class_<StepShape_CsgSelect, std::unique_ptr<StepShape_CsgSelect, Deleter<StepShape_CsgSelect>>> cls_StepShape_CsgSelect(mod, "StepShape_CsgSelect", "None");
	cls_StepShape_CsgSelect.def(py::init<>());
	cls_StepShape_CsgSelect.def("SetTypeOfContent", (void (StepShape_CsgSelect::*)(const Standard_Integer)) &StepShape_CsgSelect::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
	cls_StepShape_CsgSelect.def("TypeOfContent", (Standard_Integer (StepShape_CsgSelect::*)() const ) &StepShape_CsgSelect::TypeOfContent, "None");
	cls_StepShape_CsgSelect.def("BooleanResult", (opencascade::handle<StepShape_BooleanResult> (StepShape_CsgSelect::*)() const ) &StepShape_CsgSelect::BooleanResult, "returns Value as a BooleanResult (Null if another type)");
	cls_StepShape_CsgSelect.def("SetBooleanResult", (void (StepShape_CsgSelect::*)(const opencascade::handle<StepShape_BooleanResult> &)) &StepShape_CsgSelect::SetBooleanResult, "None", py::arg("aBooleanResult"));
	cls_StepShape_CsgSelect.def("CsgPrimitive", (StepShape_CsgPrimitive (StepShape_CsgSelect::*)() const ) &StepShape_CsgSelect::CsgPrimitive, "returns Value as a CsgPrimitive (Null if another type)");
	cls_StepShape_CsgSelect.def("SetCsgPrimitive", (void (StepShape_CsgSelect::*)(const StepShape_CsgPrimitive &)) &StepShape_CsgSelect::SetCsgPrimitive, "None", py::arg("aCsgPrimitive"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DimensionalCharacteristic.hxx
	py::class_<StepShape_DimensionalCharacteristic, std::unique_ptr<StepShape_DimensionalCharacteristic, Deleter<StepShape_DimensionalCharacteristic>>, StepData_SelectType> cls_StepShape_DimensionalCharacteristic(mod, "StepShape_DimensionalCharacteristic", "Representation of STEP SELECT type DimensionalCharacteristic");
	cls_StepShape_DimensionalCharacteristic.def(py::init<>());
	cls_StepShape_DimensionalCharacteristic.def("CaseNum", (Standard_Integer (StepShape_DimensionalCharacteristic::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_DimensionalCharacteristic::CaseNum, "Recognizes a kind of DimensionalCharacteristic select type 1 -> DimensionalLocation from StepShape 2 -> DimensionalSize from StepShape 0 else", py::arg("ent"));
	cls_StepShape_DimensionalCharacteristic.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepShape_DimensionalCharacteristic::*)() const ) &StepShape_DimensionalCharacteristic::DimensionalLocation, "Returns Value as DimensionalLocation (or Null if another type)");
	cls_StepShape_DimensionalCharacteristic.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepShape_DimensionalCharacteristic::*)() const ) &StepShape_DimensionalCharacteristic::DimensionalSize, "Returns Value as DimensionalSize (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_DirectedDimensionalLocation.hxx
	py::class_<StepShape_DirectedDimensionalLocation, opencascade::handle<StepShape_DirectedDimensionalLocation>, StepShape_DimensionalLocation> cls_StepShape_DirectedDimensionalLocation(mod, "StepShape_DirectedDimensionalLocation", "Representation of STEP entity DirectedDimensionalLocation");
	cls_StepShape_DirectedDimensionalLocation.def(py::init<>());
	cls_StepShape_DirectedDimensionalLocation.def_static("get_type_name_", (const char * (*)()) &StepShape_DirectedDimensionalLocation::get_type_name, "None");
	cls_StepShape_DirectedDimensionalLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_DirectedDimensionalLocation::get_type_descriptor, "None");
	cls_StepShape_DirectedDimensionalLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_DirectedDimensionalLocation::*)() const ) &StepShape_DirectedDimensionalLocation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfConnectedEdgeSet.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_ConnectedEdgeSet> >(mod, "StepShape_Array1OfConnectedEdgeSet");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfOrientedEdge.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_OrientedEdge> >(mod, "StepShape_Array1OfOrientedEdge");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfConnectedFaceSet.hxx
	bind_NCollection_Array1<opencascade::handle<StepShape_ConnectedFaceSet> >(mod, "StepShape_Array1OfConnectedFaceSet");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfGeometricSetSelect.hxx
	bind_NCollection_Array1<StepShape_GeometricSetSelect>(mod, "StepShape_Array1OfGeometricSetSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfShapeDimensionRepresentationItem.hxx
	bind_NCollection_Array1<StepShape_ShapeDimensionRepresentationItem>(mod, "StepShape_Array1OfShapeDimensionRepresentationItem");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfShell.hxx
	bind_NCollection_Array1<StepShape_Shell>(mod, "StepShape_Array1OfShell");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_Array1OfValueQualifier.hxx
	bind_NCollection_Array1<StepShape_ValueQualifier>(mod, "StepShape_Array1OfValueQualifier");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ToleranceMethodDefinition.hxx
	py::class_<StepShape_ToleranceMethodDefinition, std::unique_ptr<StepShape_ToleranceMethodDefinition, Deleter<StepShape_ToleranceMethodDefinition>>, StepData_SelectType> cls_StepShape_ToleranceMethodDefinition(mod, "StepShape_ToleranceMethodDefinition", "Added for Dimensional Tolerances");
	cls_StepShape_ToleranceMethodDefinition.def(py::init<>());
	cls_StepShape_ToleranceMethodDefinition.def("CaseNum", (Standard_Integer (StepShape_ToleranceMethodDefinition::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_ToleranceMethodDefinition::CaseNum, "Recognizes a kind of ValueQualifier Select Type : 1 -> ToleranceValue from StepShape 2 -> LimitsAndFits from StepShape", py::arg("ent"));
	cls_StepShape_ToleranceMethodDefinition.def("ToleranceValue", (opencascade::handle<StepShape_ToleranceValue> (StepShape_ToleranceMethodDefinition::*)() const ) &StepShape_ToleranceMethodDefinition::ToleranceValue, "Returns Value as ToleranceValue");
	cls_StepShape_ToleranceMethodDefinition.def("LimitsAndFits", (opencascade::handle<StepShape_LimitsAndFits> (StepShape_ToleranceMethodDefinition::*)() const ) &StepShape_ToleranceMethodDefinition::LimitsAndFits, "Returns Value as LimitsAndFits");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_ReversibleTopologyItem.hxx
	py::class_<StepShape_ReversibleTopologyItem, std::unique_ptr<StepShape_ReversibleTopologyItem, Deleter<StepShape_ReversibleTopologyItem>>, StepData_SelectType> cls_StepShape_ReversibleTopologyItem(mod, "StepShape_ReversibleTopologyItem", "None");
	cls_StepShape_ReversibleTopologyItem.def(py::init<>());
	cls_StepShape_ReversibleTopologyItem.def("CaseNum", (Standard_Integer (StepShape_ReversibleTopologyItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_ReversibleTopologyItem::CaseNum, "Recognizes a ReversibleTopologyItem Kind Entity that is : 1 -> Edge 2 -> Path 3 -> Face 4 -> FaceBound 5 -> ClosedShell 6 -> OpenShell 0 else", py::arg("ent"));
	cls_StepShape_ReversibleTopologyItem.def("Edge", (opencascade::handle<StepShape_Edge> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::Edge, "returns Value as a Edge (Null if another type)");
	cls_StepShape_ReversibleTopologyItem.def("Path", (opencascade::handle<StepShape_Path> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::Path, "returns Value as a Path (Null if another type)");
	cls_StepShape_ReversibleTopologyItem.def("Face", (opencascade::handle<StepShape_Face> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::Face, "returns Value as a Face (Null if another type)");
	cls_StepShape_ReversibleTopologyItem.def("FaceBound", (opencascade::handle<StepShape_FaceBound> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::FaceBound, "returns Value as a FaceBound (Null if another type)");
	cls_StepShape_ReversibleTopologyItem.def("ClosedShell", (opencascade::handle<StepShape_ClosedShell> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::ClosedShell, "returns Value as a ClosedShell (Null if another type)");
	cls_StepShape_ReversibleTopologyItem.def("OpenShell", (opencascade::handle<StepShape_OpenShell> (StepShape_ReversibleTopologyItem::*)() const ) &StepShape_ReversibleTopologyItem::OpenShell, "returns Value as a OpenShell (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_SurfaceModel.hxx
	py::class_<StepShape_SurfaceModel, std::unique_ptr<StepShape_SurfaceModel, Deleter<StepShape_SurfaceModel>>, StepData_SelectType> cls_StepShape_SurfaceModel(mod, "StepShape_SurfaceModel", "None");
	cls_StepShape_SurfaceModel.def(py::init<>());
	cls_StepShape_SurfaceModel.def("CaseNum", (Standard_Integer (StepShape_SurfaceModel::*)(const opencascade::handle<Standard_Transient> &) const ) &StepShape_SurfaceModel::CaseNum, "Recognizes a SurfaceModel Kind Entity that is : 1 -> ShellBasedSurfaceModel 2 -> FaceBasedSurfaceModel 0 else", py::arg("ent"));
	cls_StepShape_SurfaceModel.def("ShellBasedSurfaceModel", (opencascade::handle<StepShape_ShellBasedSurfaceModel> (StepShape_SurfaceModel::*)() const ) &StepShape_SurfaceModel::ShellBasedSurfaceModel, "returns Value as a ShellBasedSurfaceModel (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfFaceBound.hxx
	py::class_<StepShape_HArray1OfFaceBound, opencascade::handle<StepShape_HArray1OfFaceBound>, StepShape_Array1OfFaceBound, Standard_Transient> cls_StepShape_HArray1OfFaceBound(mod, "StepShape_HArray1OfFaceBound", "None");
	cls_StepShape_HArray1OfFaceBound.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfFaceBound.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfFaceBound::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfFaceBound.def(py::init<const StepShape_Array1OfFaceBound &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfFaceBound.def("Array1", (const StepShape_Array1OfFaceBound & (StepShape_HArray1OfFaceBound::*)() const ) &StepShape_HArray1OfFaceBound::Array1, "None");
	cls_StepShape_HArray1OfFaceBound.def("ChangeArray1", (StepShape_Array1OfFaceBound & (StepShape_HArray1OfFaceBound::*)()) &StepShape_HArray1OfFaceBound::ChangeArray1, "None");
	cls_StepShape_HArray1OfFaceBound.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfFaceBound::get_type_name, "None");
	cls_StepShape_HArray1OfFaceBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfFaceBound::get_type_descriptor, "None");
	cls_StepShape_HArray1OfFaceBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfFaceBound::*)() const ) &StepShape_HArray1OfFaceBound::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfEdge.hxx
	py::class_<StepShape_HArray1OfEdge, opencascade::handle<StepShape_HArray1OfEdge>, StepShape_Array1OfEdge, Standard_Transient> cls_StepShape_HArray1OfEdge(mod, "StepShape_HArray1OfEdge", "None");
	cls_StepShape_HArray1OfEdge.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfEdge.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfEdge::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfEdge.def(py::init<const StepShape_Array1OfEdge &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfEdge.def("Array1", (const StepShape_Array1OfEdge & (StepShape_HArray1OfEdge::*)() const ) &StepShape_HArray1OfEdge::Array1, "None");
	cls_StepShape_HArray1OfEdge.def("ChangeArray1", (StepShape_Array1OfEdge & (StepShape_HArray1OfEdge::*)()) &StepShape_HArray1OfEdge::ChangeArray1, "None");
	cls_StepShape_HArray1OfEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfEdge::get_type_name, "None");
	cls_StepShape_HArray1OfEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfEdge::get_type_descriptor, "None");
	cls_StepShape_HArray1OfEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfEdge::*)() const ) &StepShape_HArray1OfEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfConnectedEdgeSet.hxx
	py::class_<StepShape_HArray1OfConnectedEdgeSet, opencascade::handle<StepShape_HArray1OfConnectedEdgeSet>, StepShape_Array1OfConnectedEdgeSet, Standard_Transient> cls_StepShape_HArray1OfConnectedEdgeSet(mod, "StepShape_HArray1OfConnectedEdgeSet", "None");
	cls_StepShape_HArray1OfConnectedEdgeSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfConnectedEdgeSet.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfConnectedEdgeSet::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfConnectedEdgeSet.def(py::init<const StepShape_Array1OfConnectedEdgeSet &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfConnectedEdgeSet.def("Array1", (const StepShape_Array1OfConnectedEdgeSet & (StepShape_HArray1OfConnectedEdgeSet::*)() const ) &StepShape_HArray1OfConnectedEdgeSet::Array1, "None");
	cls_StepShape_HArray1OfConnectedEdgeSet.def("ChangeArray1", (StepShape_Array1OfConnectedEdgeSet & (StepShape_HArray1OfConnectedEdgeSet::*)()) &StepShape_HArray1OfConnectedEdgeSet::ChangeArray1, "None");
	cls_StepShape_HArray1OfConnectedEdgeSet.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfConnectedEdgeSet::get_type_name, "None");
	cls_StepShape_HArray1OfConnectedEdgeSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfConnectedEdgeSet::get_type_descriptor, "None");
	cls_StepShape_HArray1OfConnectedEdgeSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfConnectedEdgeSet::*)() const ) &StepShape_HArray1OfConnectedEdgeSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfFace.hxx
	py::class_<StepShape_HArray1OfFace, opencascade::handle<StepShape_HArray1OfFace>, StepShape_Array1OfFace, Standard_Transient> cls_StepShape_HArray1OfFace(mod, "StepShape_HArray1OfFace", "None");
	cls_StepShape_HArray1OfFace.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfFace.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfFace::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfFace.def(py::init<const StepShape_Array1OfFace &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfFace.def("Array1", (const StepShape_Array1OfFace & (StepShape_HArray1OfFace::*)() const ) &StepShape_HArray1OfFace::Array1, "None");
	cls_StepShape_HArray1OfFace.def("ChangeArray1", (StepShape_Array1OfFace & (StepShape_HArray1OfFace::*)()) &StepShape_HArray1OfFace::ChangeArray1, "None");
	cls_StepShape_HArray1OfFace.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfFace::get_type_name, "None");
	cls_StepShape_HArray1OfFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfFace::get_type_descriptor, "None");
	cls_StepShape_HArray1OfFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfFace::*)() const ) &StepShape_HArray1OfFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfConnectedFaceSet.hxx
	py::class_<StepShape_HArray1OfConnectedFaceSet, opencascade::handle<StepShape_HArray1OfConnectedFaceSet>, StepShape_Array1OfConnectedFaceSet, Standard_Transient> cls_StepShape_HArray1OfConnectedFaceSet(mod, "StepShape_HArray1OfConnectedFaceSet", "None");
	cls_StepShape_HArray1OfConnectedFaceSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfConnectedFaceSet.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfConnectedFaceSet::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfConnectedFaceSet.def(py::init<const StepShape_Array1OfConnectedFaceSet &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfConnectedFaceSet.def("Array1", (const StepShape_Array1OfConnectedFaceSet & (StepShape_HArray1OfConnectedFaceSet::*)() const ) &StepShape_HArray1OfConnectedFaceSet::Array1, "None");
	cls_StepShape_HArray1OfConnectedFaceSet.def("ChangeArray1", (StepShape_Array1OfConnectedFaceSet & (StepShape_HArray1OfConnectedFaceSet::*)()) &StepShape_HArray1OfConnectedFaceSet::ChangeArray1, "None");
	cls_StepShape_HArray1OfConnectedFaceSet.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfConnectedFaceSet::get_type_name, "None");
	cls_StepShape_HArray1OfConnectedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfConnectedFaceSet::get_type_descriptor, "None");
	cls_StepShape_HArray1OfConnectedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfConnectedFaceSet::*)() const ) &StepShape_HArray1OfConnectedFaceSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfGeometricSetSelect.hxx
	py::class_<StepShape_HArray1OfGeometricSetSelect, opencascade::handle<StepShape_HArray1OfGeometricSetSelect>, StepShape_Array1OfGeometricSetSelect, Standard_Transient> cls_StepShape_HArray1OfGeometricSetSelect(mod, "StepShape_HArray1OfGeometricSetSelect", "None");
	cls_StepShape_HArray1OfGeometricSetSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfGeometricSetSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfGeometricSetSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfGeometricSetSelect.def(py::init<const StepShape_Array1OfGeometricSetSelect &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfGeometricSetSelect.def("Array1", (const StepShape_Array1OfGeometricSetSelect & (StepShape_HArray1OfGeometricSetSelect::*)() const ) &StepShape_HArray1OfGeometricSetSelect::Array1, "None");
	cls_StepShape_HArray1OfGeometricSetSelect.def("ChangeArray1", (StepShape_Array1OfGeometricSetSelect & (StepShape_HArray1OfGeometricSetSelect::*)()) &StepShape_HArray1OfGeometricSetSelect::ChangeArray1, "None");
	cls_StepShape_HArray1OfGeometricSetSelect.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfGeometricSetSelect::get_type_name, "None");
	cls_StepShape_HArray1OfGeometricSetSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfGeometricSetSelect::get_type_descriptor, "None");
	cls_StepShape_HArray1OfGeometricSetSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfGeometricSetSelect::*)() const ) &StepShape_HArray1OfGeometricSetSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfOrientedClosedShell.hxx
	py::class_<StepShape_HArray1OfOrientedClosedShell, opencascade::handle<StepShape_HArray1OfOrientedClosedShell>, StepShape_Array1OfOrientedClosedShell, Standard_Transient> cls_StepShape_HArray1OfOrientedClosedShell(mod, "StepShape_HArray1OfOrientedClosedShell", "None");
	cls_StepShape_HArray1OfOrientedClosedShell.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfOrientedClosedShell.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfOrientedClosedShell::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfOrientedClosedShell.def(py::init<const StepShape_Array1OfOrientedClosedShell &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfOrientedClosedShell.def("Array1", (const StepShape_Array1OfOrientedClosedShell & (StepShape_HArray1OfOrientedClosedShell::*)() const ) &StepShape_HArray1OfOrientedClosedShell::Array1, "None");
	cls_StepShape_HArray1OfOrientedClosedShell.def("ChangeArray1", (StepShape_Array1OfOrientedClosedShell & (StepShape_HArray1OfOrientedClosedShell::*)()) &StepShape_HArray1OfOrientedClosedShell::ChangeArray1, "None");
	cls_StepShape_HArray1OfOrientedClosedShell.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfOrientedClosedShell::get_type_name, "None");
	cls_StepShape_HArray1OfOrientedClosedShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfOrientedClosedShell::get_type_descriptor, "None");
	cls_StepShape_HArray1OfOrientedClosedShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfOrientedClosedShell::*)() const ) &StepShape_HArray1OfOrientedClosedShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfOrientedEdge.hxx
	py::class_<StepShape_HArray1OfOrientedEdge, opencascade::handle<StepShape_HArray1OfOrientedEdge>, StepShape_Array1OfOrientedEdge, Standard_Transient> cls_StepShape_HArray1OfOrientedEdge(mod, "StepShape_HArray1OfOrientedEdge", "None");
	cls_StepShape_HArray1OfOrientedEdge.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfOrientedEdge.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfOrientedEdge::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfOrientedEdge.def(py::init<const StepShape_Array1OfOrientedEdge &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfOrientedEdge.def("Array1", (const StepShape_Array1OfOrientedEdge & (StepShape_HArray1OfOrientedEdge::*)() const ) &StepShape_HArray1OfOrientedEdge::Array1, "None");
	cls_StepShape_HArray1OfOrientedEdge.def("ChangeArray1", (StepShape_Array1OfOrientedEdge & (StepShape_HArray1OfOrientedEdge::*)()) &StepShape_HArray1OfOrientedEdge::ChangeArray1, "None");
	cls_StepShape_HArray1OfOrientedEdge.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfOrientedEdge::get_type_name, "None");
	cls_StepShape_HArray1OfOrientedEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfOrientedEdge::get_type_descriptor, "None");
	cls_StepShape_HArray1OfOrientedEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfOrientedEdge::*)() const ) &StepShape_HArray1OfOrientedEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfShapeDimensionRepresentationItem.hxx
	py::class_<StepShape_HArray1OfShapeDimensionRepresentationItem, opencascade::handle<StepShape_HArray1OfShapeDimensionRepresentationItem>, StepShape_Array1OfShapeDimensionRepresentationItem, Standard_Transient> cls_StepShape_HArray1OfShapeDimensionRepresentationItem(mod, "StepShape_HArray1OfShapeDimensionRepresentationItem", "None");
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfShapeDimensionRepresentationItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def(py::init<const StepShape_Array1OfShapeDimensionRepresentationItem &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def("Array1", (const StepShape_Array1OfShapeDimensionRepresentationItem & (StepShape_HArray1OfShapeDimensionRepresentationItem::*)() const ) &StepShape_HArray1OfShapeDimensionRepresentationItem::Array1, "None");
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def("ChangeArray1", (StepShape_Array1OfShapeDimensionRepresentationItem & (StepShape_HArray1OfShapeDimensionRepresentationItem::*)()) &StepShape_HArray1OfShapeDimensionRepresentationItem::ChangeArray1, "None");
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfShapeDimensionRepresentationItem::get_type_name, "None");
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfShapeDimensionRepresentationItem::get_type_descriptor, "None");
	cls_StepShape_HArray1OfShapeDimensionRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfShapeDimensionRepresentationItem::*)() const ) &StepShape_HArray1OfShapeDimensionRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfShell.hxx
	py::class_<StepShape_HArray1OfShell, opencascade::handle<StepShape_HArray1OfShell>, StepShape_Array1OfShell, Standard_Transient> cls_StepShape_HArray1OfShell(mod, "StepShape_HArray1OfShell", "None");
	cls_StepShape_HArray1OfShell.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfShell.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfShell::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfShell.def(py::init<const StepShape_Array1OfShell &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfShell.def("Array1", (const StepShape_Array1OfShell & (StepShape_HArray1OfShell::*)() const ) &StepShape_HArray1OfShell::Array1, "None");
	cls_StepShape_HArray1OfShell.def("ChangeArray1", (StepShape_Array1OfShell & (StepShape_HArray1OfShell::*)()) &StepShape_HArray1OfShell::ChangeArray1, "None");
	cls_StepShape_HArray1OfShell.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfShell::get_type_name, "None");
	cls_StepShape_HArray1OfShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfShell::get_type_descriptor, "None");
	cls_StepShape_HArray1OfShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfShell::*)() const ) &StepShape_HArray1OfShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepShape_HArray1OfValueQualifier.hxx
	py::class_<StepShape_HArray1OfValueQualifier, opencascade::handle<StepShape_HArray1OfValueQualifier>, StepShape_Array1OfValueQualifier, Standard_Transient> cls_StepShape_HArray1OfValueQualifier(mod, "StepShape_HArray1OfValueQualifier", "None");
	cls_StepShape_HArray1OfValueQualifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepShape_HArray1OfValueQualifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepShape_Array1OfValueQualifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepShape_HArray1OfValueQualifier.def(py::init<const StepShape_Array1OfValueQualifier &>(), py::arg("theOther"));
	cls_StepShape_HArray1OfValueQualifier.def("Array1", (const StepShape_Array1OfValueQualifier & (StepShape_HArray1OfValueQualifier::*)() const ) &StepShape_HArray1OfValueQualifier::Array1, "None");
	cls_StepShape_HArray1OfValueQualifier.def("ChangeArray1", (StepShape_Array1OfValueQualifier & (StepShape_HArray1OfValueQualifier::*)()) &StepShape_HArray1OfValueQualifier::ChangeArray1, "None");
	cls_StepShape_HArray1OfValueQualifier.def_static("get_type_name_", (const char * (*)()) &StepShape_HArray1OfValueQualifier::get_type_name, "None");
	cls_StepShape_HArray1OfValueQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HArray1OfValueQualifier::get_type_descriptor, "None");
	cls_StepShape_HArray1OfValueQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HArray1OfValueQualifier::*)() const ) &StepShape_HArray1OfValueQualifier::DynamicType, "None");


}
