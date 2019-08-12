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
#include <IGESDimen_Protocol.hxx>
#include <IGESDimen_CenterLine.hxx>
#include <IGESDimen_Section.hxx>
#include <IGESDimen_WitnessLine.hxx>
#include <IGESDimen_AngularDimension.hxx>
#include <IGESDimen_CurveDimension.hxx>
#include <IGESDimen_DiameterDimension.hxx>
#include <IGESDimen_FlagNote.hxx>
#include <IGESDimen_GeneralLabel.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESDimen_NewGeneralNote.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_LinearDimension.hxx>
#include <IGESDimen_OrdinateDimension.hxx>
#include <IGESDimen_PointDimension.hxx>
#include <IGESDimen_RadiusDimension.hxx>
#include <IGESDimen_GeneralSymbol.hxx>
#include <IGESDimen_SectionedArea.hxx>
#include <IGESDimen_DimensionedGeometry.hxx>
#include <IGESDimen_NewDimensionedGeometry.hxx>
#include <IGESDimen_DimensionUnits.hxx>
#include <IGESDimen_DimensionTolerance.hxx>
#include <IGESDimen_DimensionDisplayData.hxx>
#include <IGESDimen_BasicDimension.hxx>
#include <IGESDimen_ToolCenterLine.hxx>
#include <IGESDimen_ToolSection.hxx>
#include <IGESDimen_ToolWitnessLine.hxx>
#include <IGESDimen_ToolAngularDimension.hxx>
#include <IGESDimen_ToolCurveDimension.hxx>
#include <IGESDimen_ToolDiameterDimension.hxx>
#include <IGESDimen_ToolFlagNote.hxx>
#include <IGESDimen_ToolGeneralLabel.hxx>
#include <IGESDimen_ToolGeneralNote.hxx>
#include <IGESDimen_ToolNewGeneralNote.hxx>
#include <IGESDimen_ToolLeaderArrow.hxx>
#include <IGESDimen_ToolLinearDimension.hxx>
#include <IGESDimen_ToolOrdinateDimension.hxx>
#include <IGESDimen_ToolPointDimension.hxx>
#include <IGESDimen_ToolRadiusDimension.hxx>
#include <IGESDimen_ToolGeneralSymbol.hxx>
#include <IGESDimen_ToolSectionedArea.hxx>
#include <IGESDimen_ToolDimensionedGeometry.hxx>
#include <IGESDimen_ToolNewDimensionedGeometry.hxx>
#include <IGESDimen_ToolDimensionUnits.hxx>
#include <IGESDimen_ToolDimensionTolerance.hxx>
#include <IGESDimen_ToolDimensionDisplayData.hxx>
#include <IGESDimen_ToolBasicDimension.hxx>
#include <IGESDimen_ReadWriteModule.hxx>
#include <IGESDimen_GeneralModule.hxx>
#include <IGESDimen_SpecificModule.hxx>
#include <IGESDimen.hxx>

void bind_IGESDimen(py::module &mod){

py::class_<IGESDimen, std::unique_ptr<IGESDimen, Deleter<IGESDimen>>> cls_IGESDimen(mod, "IGESDimen", "This package represents Entities applied to Dimensions ie. Annotation Entities and attached Properties and Associativities.");

// Constructors

// Fields

// Methods
// cls_IGESDimen.def_static("operator new_", (void * (*)(size_t)) &IGESDimen::operator new, "None", py::arg("theSize"));
// cls_IGESDimen.def_static("operator delete_", (void (*)(void *)) &IGESDimen::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen.def_static("Init_", (void (*)()) &IGESDimen::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESDimen.def_static("Protocol_", (opencascade::handle<IGESDimen_Protocol> (*)()) &IGESDimen::Protocol, "Returns the Protocol for this Package");

// Enums

}