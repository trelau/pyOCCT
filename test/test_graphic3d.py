# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest

from OCCT.Graphic3d import (Graphic3d_RenderingParams,
        Graphic3d_RM_RASTERIZATION, Graphic3d_RM_RAYTRACING,
        Graphic3d_RTM_BLEND_UNORDERED, Graphic3d_RTM_BLEND_OIT,
        Graphic3d_StereoMode_QuadBuffer, Graphic3d_StereoMode_SideBySide,
        Graphic3d_ToneMappingMethod_Disabled,
        Graphic3d_ToneMappingMethod_Filmic)


class TestGraphic3dRenderingParams(unittest.TestCase):
    """
    Test for Data Fields of Graphic3d_RenderingParams
    """

    def test_AdaptiveScreenSampling(self):
        """
        Test AdaptiveScreenSampling data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.AdaptiveScreenSampling
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.AdaptiveScreenSampling
        self.assertEqual(val, True, 'set/get error')

    def test_AnaglyphFilter(self):
        """
        Test AnaglyphFilter data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.AnaglyphFilter
        self.assertEqual(val, Graphic3d_RenderingParams.Anaglyph.Anaglyph_RedCyan_Optimized, 'incorrect default')

        p.Method = Graphic3d_RenderingParams.Anaglyph.Anaglyph_GreenMagenta_Simple
        val = p.AnaglyphFilter
        self.assertEqual(val, Graphic3d_RenderingParams.Anaglyph.Anaglyph_GreenMagenta_Simple, 'set/get error')

    def test_CameraApertureRadius(self):
        """
        Test CameraApertureRadius data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.CameraApertureRadius
        self.assertAlmostEqual(val, 0.0, 'incorrect default')

        p.Method = 1.0
        val = p.CameraApertureRadius
        self.assertAlmostEqual(val, 1.0, 'set/get error')

    def test_CameraFocalPlaneDist(self):
        """
        Test CameraFocalPlaneDist data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.CameraFocalPlaneDist
        self.assertAlmostEqual(val, 1.0, 'incorrect default')

        p.Method = 2.0
        val = p.CameraFocalPlaneDist
        self.assertAlmostEqual(val, 2.0, 'set/get error')

    def test_CoherentPathTracingMode(self):
        """
        Test CoherentPathTracingMode data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.CoherentPathTracingMode
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.CoherentPathTracingMode
        self.assertEqual(val, True, 'set/get error')

    def test_Exposure(self):
        """
        Test Exposure data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.Exposure
        self.assertAlmostEqual(val, 0.0, 'incorrect default')

        p.Method = 1.0
        val = p.Exposure
        self.assertAlmostEqual(val, 1.0, 'set/get error')

    def test_IsAntialiasingEnabled(self):
        """
        Test IsAntialiasingEnabled data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.IsAntialiasingEnabled
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.IsAntialiasingEnabled
        self.assertEqual(val, True, 'set/get error')

    def test_IsGlobalIlluminationEnabled(self):
        """
        Test IsGlobalIlluminationEnabled data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.IsGlobalIlluminationEnabled
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.IsGlobalIlluminationEnabled
        self.assertEqual(val, True, 'set/get error')

    def test_IsReflectionEnabled(self):
        """
        Test IsReflectionEnabled data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.IsReflectionEnabled
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.IsReflectionEnabled
        self.assertEqual(val, True, 'set/get error')

    def test_IsShadowEnabled(self):
        """
        Test IsShadowEnabled data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.IsShadowEnabled
        self.assertEqual(val, True, 'incorrect default')

        p.Method = False
        val = p.IsShadowEnabled
        self.assertEqual(val, False, 'set/get error')

    def test_IsTransparentShadowEnabled(self):
        """
        Test IsTransparentShadowEnabled data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.IsTransparentShadowEnabled
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.IsTransparentShadowEnabled
        self.assertEqual(val, True, 'set/get error')

    def test_Method(self):
        """
        Test Method data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.Method
        self.assertEqual(val, Graphic3d_RM_RASTERIZATION, 'incorrect default')

        p.Method = Graphic3d_RM_RAYTRACING
        val = p.Method
        self.assertEqual(val, Graphic3d_RM_RAYTRACING, 'set/get error')

    def test_NbMsaaSamples(self):
        """
        Test NbMsaaSamples data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.NbMsaaSamples
        self.assertEqual(val, 0, 'incorrect default')

        p.Method = 2
        val = p.NbMsaaSamples
        self.assertEqual(val, 2, 'set/get error')

    def test_NbRayTracingTiles(self):
        """
        Test NbRayTracingTiles data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.NbRayTracingTiles
        self.assertEqual(val, 0, 'incorrect default')

        p.Method = 2
        val = p.NbRayTracingTiles
        self.assertEqual(val, 2, 'set/get error')

    def test_OitDepthFactor(self):
        """
        Test OitDepthFactor data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.OitDepthFactor
        self.assertAlmostEqual(val, 0.0, 'incorrect default')

        p.Method = 0.5
        val = p.OitDepthFactor
        self.assertAlmostEqual(val, 0.5, 'set/get error')

    def test_RadianceClampingValue(self):
        """
        Test RadianceClampingValue data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.RadianceClampingValue
        self.assertAlmostEqual(val, 0.0, 'incorrect default')

        p.Method = 0.5
        val = p.RadianceClampingValue
        self.assertAlmostEqual(val, 0.5, 'set/get error')

    def test_RaytracingDepth(self):
        """
        Test RaytracingDepth data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.RaytracingDepth
        self.assertEqual(val, 3, 'incorrect default')

        p.Method = 4
        val = p.RaytracingDepth
        self.assertEqual(val, 4, 'set/get error')

    def test_RebuildRayTracingShaders(self):
        """
        Test RebuildRayTracingShaders data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.RebuildRayTracingShaders
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.RebuildRayTracingShaders
        self.assertEqual(val, True, 'set/get error')

    def test_RenderResolutionScale(self):
        """
        Test RenderResolutionScale data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.RenderResolutionScale
        self.assertAlmostEqual(val, 1.0, 'incorrect default')

        p.Method = 2.0
        val = p.RenderResolutionScale
        self.assertAlmostEqual(val, 2.0, 'set/get error')

    def test_Resolution(self):
        """
        Test Resolution data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.Resolution
        self.assertEqual(val, 72, 'incorrect default')

        p.Method = 96
        val = p.Resolution
        self.assertEqual(val, 96, 'set/get error')

    def test_SamplesPerPixel(self):
        """
        Test SamplesPerPixel data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.SamplesPerPixel
        self.assertEqual(val, 1, 'incorrect default')

        p.Method = 2
        val = p.SamplesPerPixel
        self.assertEqual(val, 2, 'set/get error')

    def test_ShowSamplingTiles(self):
        """
        Test ShowSamplingTiles data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.ShowSamplingTiles
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.ShowSamplingTiles
        self.assertEqual(val, True, 'set/get error')

    def test_StereoMode(self):
        """
        Test StereoMode data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.StereoMode
        self.assertEqual(val, Graphic3d_StereoMode_QuadBuffer, 'incorrect default')

        p.Method = Graphic3d_StereoMode_SideBySide
        val = p.StereoMode
        self.assertEqual(val, Graphic3d_StereoMode_SideBySide, 'set/get error')

    def test_THE_DEFAULT_DEPTH(self):
        """
        Test THE_DEFAULT_DEPTH data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.THE_DEFAULT_DEPTH
        self.assertEqual(val, 3, 'incorrect default')

        p.Method = 4
        val = p.THE_DEFAULT_DEPTH
        self.assertEqual(val, 4, 'set/get error')

    def test_THE_DEFAULT_RESOLUTION(self):
        """
        Test THE_DEFAULT_RESOLUTION data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.THE_DEFAULT_RESOLUTION
        self.assertEqual(val, 72, 'incorrect default')

        p.Method = 96
        val = p.THE_DEFAULT_RESOLUTION
        self.assertEqual(val, 96, 'set/get error')

    def test_ToneMappingMethod(self):
        """
        Test ToneMappingMethod data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.ToneMappingMethod
        self.assertEqual(val, Graphic3d_ToneMappingMethod_Disabled, 'incorrect default')

        p.Method = Graphic3d_ToneMappingMethod_Filmic
        val = p.ToneMappingMethod
        self.assertEqual(val, Graphic3d_ToneMappingMethod_Filmic, 'set/get error')

    def test_ToReverseStereo(self):
        """
        Test ToReverseStereo data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.ToReverseStereo
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.ToReverseStereo
        self.assertEqual(val, True, 'set/get error')

    def test_TransparencyMethod(self):
        """
        Test TransparencyMethod data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.TransparencyMethod
        self.assertEqual(val, Graphic3d_RTM_BLEND_UNORDERED, 'incorrect default')

        p.Method = Graphic3d_RTM_BLEND_OIT
        val = p.TransparencyMethod
        self.assertEqual(val, Graphic3d_RTM_BLEND_OIT, 'set/get error')

    def test_TwoSidedBsdfModels(self):
        """
        Test TwoSidedBsdfModels data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.TwoSidedBsdfModels
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.TwoSidedBsdfModels
        self.assertEqual(val, True, 'set/get error')

    def test_UseEnvironmentMapBackground(self):
        """
        Test UseEnvironmentMapBackground data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.UseEnvironmentMapBackground
        self.assertEqual(val, False, 'incorrect default')

        p.Method = True
        val = p.UseEnvironmentMapBackground
        self.assertEqual(val, True, 'set/get error')

    def test_WhitePoint(self):
        """
        Test WhitePoint data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.WhitePoint
        self.assertAlmostEqual(val, 1.0, 'incorrect default')

        p.Method = 2.0
        val = p.WhitePoint
        self.assertAlmostEqual(val, 2.0, 'set/get error')

if __name__ == '__main__':
    unittest.main()
