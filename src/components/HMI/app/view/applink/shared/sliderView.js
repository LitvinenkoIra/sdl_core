/**
 * @name MFT.SliderView
 * 
 * @desc Slider visual representation
 * 
 * @category	View
 * @filesource	app/view/applink/shared/sliderView.js
 * @version		1.0
 *
 * @author		Artem Petrosyan
 */
 
MFT.SliderView = MFT.ApplinkAbstractView.create({
	
	elementId: 'slider_view',
	
	childViews: [
		'backButton',
		'captionText',
		'headerLabel',
		'footerLabel',
		'adjustControl'
	],
	
	headerLabel: MFT.Label.extend({
		classNames:	'slider-header',
		content:	'Header Label'
	}),
	
	footerLabel: MFT.Label.extend({
		classNames:	'slider-footer',
		content:	'Footer Label'
	}),
		
	adjustControl: Em.ContainerView.extend({
		
		classNames:         'sliderControl',
		
		childViews: [
			'minusBtn',
			'led',
			'plusBtn'
		],
		
		sliderValue:	MFT.RangedValue.create({range: 10, value:0, cycle: false, minValue: 0}),
		
		minusBtn: MFT.Button.extend({
			classNames: 'control minus',
			icon:       'images/common/minus-ico.png',
			actionDown: function() {
				this._super();
				this.get('parentView.sliderValue').decrease();
				FFW.UI.sendSliderResult("SUCCESS", this.get('parentView.sliderValue.value') );
			}
		}),
		
		led: MFT.Indicator.create({
			classNames:         'ledContainer ico',
			contentBinding:     'parentView.sliderValue',
			indActiveClass:     'led',
			indDefaultClass:    'led-inactive',
		}),
		
		plusBtn: MFT.Button.extend({
			classNames: 'control plus',
			icon:       'images/common/plus-ico.png',
			actionDown: function() {
				this._super();
				this.get('parentView.sliderValue').increase();
				FFW.UI.sendSliderResult("SUCCESS", this.get('parentView.sliderValue.value') );
			}
		})
	}),
	
    loadData: function( data ){
		this.set( 'headerLabel.content', data.sliderHeader );
		this.set( 'footerLabel.content', data.sliderFooter[0] );
		this.get( 'adjustControl.sliderValue').set('range',data.numTicks);
		this.get( 'adjustControl.sliderValue').set('value',data.position);

		setTimeout(function(){
			MFT.SliderView.adjustControl.rerender();
		},1);
    }
});
